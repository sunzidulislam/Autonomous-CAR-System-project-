  
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void setup() {
Serial.begin(9600);
  Serial.println("HMC5883 Magnetometer Test");
 
  /* Initialise the sensor */
  if (!mag.begin())
  {
    /* There was a problem detecting the HMC5883 ... check your connections */
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while (1);
  }
}

void loop() {
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
}
