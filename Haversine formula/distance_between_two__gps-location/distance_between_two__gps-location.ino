#include <Arduino.h>
#include <math.h>

#define R 6371000.0  // Earth's radius in meters

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
double distance;

void setup() {
  Serial.begin(9600);
  
  double lat1 = 37.7749;  // Example latitude for point 1
  double lon1 = -122.4194;  // Example longitude for point 1
  double lat2 = 34.0522;  // Example latitude for point 2
  double lon2 = -118.2437;  // Example longitude for point 2

   distance = haversine(lat1, lon1, lat2, lon2);
  
  Serial.print("Distance between points: ");
  Serial.print(distance*100);
  Serial.println(" cm");
}

void loop() {
 while(distance>0.5111)
}
