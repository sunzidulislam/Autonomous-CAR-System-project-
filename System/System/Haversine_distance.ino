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

double toRadians(double degree) {
  return degree * (M_PI / 180.0);
}
