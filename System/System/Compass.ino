int heading_angle(){
  
  sensors_event_t event;
  mag.getEvent(&event);
 
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);
 
  float declinationAngle = 0.53;
  heading += declinationAngle;
 
  // Correct for when signs are reversed.
  if (heading < 0)
    heading += 2 * PI;
 
  // Check for wrap due to addition of declination.
  if (heading > 2 * PI)
    heading -= 2 * PI;
 
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180 / M_PI;
  Serial.println(headingDegrees);
  ble.print("headingDegrees: ");
  ble.println(headingDegrees);
  int x=headingDegrees;
  ble.print("x: ");
  ble.println(x);
 return  x;
}
