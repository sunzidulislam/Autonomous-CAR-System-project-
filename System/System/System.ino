#include <Arduino.h>
#include <math.h>
#include <TinyGPS++.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <SoftwareSerial.h>


SoftwareSerial GPS_SoftSerial(4, 3);
SoftwareSerial ble(7, 6);
TinyGPSPlus gps;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);


int rms=10;
int rmf=12;
int rmb=13;

int lms=9;
int lmf=8;
int lmb=11;

#define spl 20
#define spr 19

#define R 6371000.0  // Earth's radius in meters

int angle(int target,int current);
void motor(int a, int b);

double current_latitude=0;
double current_longitude=0;

double destination_latitude=0;
double destination_longitude=0;

int error=0;

void setup() {
  Serial.begin(9600); 
  ble.begin(9600);
  GPS_SoftSerial.begin(9600);



 if (!mag.begin())
  {
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while (1);
  }

}

void loop() {
  //target_locaion();
   Gps();
   int current_angle;
   int target_angle;
  while(haversine(current_latitude, current_longitude, destination_latitude, destination_longitude)<=50){
    current_angle=heading_angle();
    target_angle=calculateWaypointAngle(current_latitude, current_longitude, destination_latitude, destination_longitude);
    int pos= angle (target_angle,current_angle);


  
  if (error == 0.00) {motor(10 * spl, 10 * spr);}
  //if (error>=0.0 && error<=5.0) {motor(10 * spl, 10 * spr);}
  else{
    
    if(pos==0){
        if (error>0.0 && error<=36.0 ) motor(9 * spl, 10 * spr);
        else if (error>36.0 && error<=72.0  ) motor(6 * spl, 10 * spr);
        else if (error>72.0 && error<=108.0) motor(3 * spl, 10 * spr);
        else if (error>108.0 && error<=144.0 ) motor(0 * spl, 10 * spr);
        else if    (error>144.0 && error<=180.0 ) motor(-3 * spl, 10 * spr);
    }

    else{
        
        if (error>0.0 && error<=36.0) motor(10 * spl, 9 * spr);
        else if (error>36.0 && error<=72.0  ) motor(10 * spl, 6 * spr);
        else if (error>72.0 && error<=108.0) motor(10 * spl, 3 * spr);
        else if (error>108.0 && error<=144.0) motor(10 * spl, 0 * spr);
        else if (error>144.0 && error<=180.0) motor(10 * spl, -3 * spr);
        
    }   
  }


    Gps();
  }

  motor(0* spl, 0* spr);
}
