void Gps (){
  
  smartDelay(1000); /* Generate precise delay of 1ms */
        unsigned long start;
        double lat_val, lng_val;
       
        bool loc_valid;
        lat_val = gps.location.lat(); 
        loc_valid = gps.location.isValid(); /* Check if valid location data is available */
        lng_val = gps.location.lng(); /* Get longtitude data */
         /* Check if valid altitude data is available */
          /* Check if valid time data is available */
     while(1){

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
          Serial.println(lat_val, 5);
        
          ble.print("Latitude in Decimal Degrees : ");
          ble.println(lat_val, 5);
          
          current_latitude=lat_val;



          

          
          Serial.print("Longitude in Decimal Degrees : ");
          Serial.println(lng_val, 5);

          ble.print("Longitude in Decimal Degrees : ");
          ble.println(lng_val, 5);

          current_longitude=lng_val;
          
          break;
          
         }
        smartDelay(1000);
        lat_val = gps.location.lat(); /* Get latitude data */
        loc_valid = gps.location.isValid(); /* Check if valid location data is available */
        lng_val = gps.location.lng();
     
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
