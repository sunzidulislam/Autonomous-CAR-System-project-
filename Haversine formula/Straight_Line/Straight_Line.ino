#include <Arduino.h>
#include <math.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define R 6371000.0  // Earth's radius in meters
double target_lat_val;
double target_lng_val;

SoftwareSerial GPS_SoftSerial(4, 3);
SoftwareSerial ble(7, 6);
TinyGPSPlus gps; 

int rms;
int rmf;
int rmb;

int lms;
int lmf;
int lmb;



double toRadians(double degree) {
  return degree * (M_PI / 180.0);
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
  double phi1 = toRadians(lat1);
  double phi2 = toRadians(lat2);
  double deltaPhi = toRadians(lat2 - lat1);
  double deltaLambda = toRadians(lon2 - lon1);

  double a = sin(deltaPhi / 2.0) * sin(deltaPhi / 2.0) +
             cos(phi1) * cos(phi2) * sin(deltaLambda / 2.0) * sin(deltaLambda / 2.0);

  double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

  double distance = R * c;
  return distance;
}
void setup() {
  Serial.begin(9600); 
  ble.begin(9600);
  GPS_SoftSerial.begin(9600);
  pinMode(rmf,OUTPUT);
  pinMode(rmb,OUTPUT);
  pinMode(lmf,OUTPUT);
  pinMode(lmb,OUTPUT);
  pinMode(rms,OUTPUT);
  pinMode(lms,OUTPUT);
  
  
}

void loop() {
  
  //<------------------------------------GPS--------------------------->

   smartDelay(1000); /* Generate precise delay of 1ms */
        unsigned long start;
        double lat_val, lng_val;
       
        bool loc_valid;
        lat_val = gps.location.lat(); /* Get latitude data */
        loc_valid = gps.location.isValid(); /* Check if valid location data is available */
        lng_val = gps.location.lng(); /* Get longtitude data */
         /* Check if valid altitude data is available */
          /* Check if valid time data is available */
        if (!loc_valid)
        {          
          Serial.print("Latitude : ");
          Serial.println("***");
          Serial.print("Longitude : ");
          Serial.println("***");
          ble.print("Latitude : ");
          ble.println("***");
          ble.print("Longitude : ");
          ble.println("***");
        }
        else
        {
          
          Serial.print("Latitude in Decimal Degrees : ");
          Serial.println(lat_val, 6);

          ble.print("Latitude in Decimal Degrees : ");
          ble.println(lat_val, 5);
          
          Serial.print("Longitude in Decimal Degrees : ");
          Serial.println(lng_val, 6);

          ble.print("Longitude in Decimal Degrees : ");
          ble.println(lng_val, 5);
          
          
        }


  //<-----------------------------------END_GPS------------------------------->

  //<-----------------------------------Haver sine---------------------------->
  

    double distance = haversine(target_lat_val, target_lng_val, lat_val, lng_val);
    ble.print("Distance : ");
    ble.println(distance, 5);
   if(distance>0.6000){
     
       digitalWrite(rmf,HIGH);
       digitalWrite(rmb,LOW); 

       digitalWrite(lmf,HIGH);
       digitalWrite(lmb,LOW);
       
       analogWrite(rms,180);
       analogWrite(lms,180);
   }

  else{
    
       digitalWrite(rmf,LOW);
       digitalWrite(rmb,LOW); 

       digitalWrite(lmf,LOW);
       digitalWrite(lmb,LOW);
       
       analogWrite(rms,0);
       analogWrite(lms,0);
    
      ble.print("!!!!Destination reached!!! ");
    
  }

}



static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (GPS_SoftSerial.available())  /* Encode data read from GPS while data is available on serial port */
      gps.encode(GPS_SoftSerial.read());
/* Encode basically is used to parse the string received by the GPS and to store it in a buffer so that information can be extracted from it */
  } while (millis() - start < ms);
}
