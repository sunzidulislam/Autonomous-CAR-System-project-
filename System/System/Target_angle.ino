double calculateWaypointAngle(double carLat, double carLng, double targetLat, double targetLng) {
    
    // Convert latitude and longitude from degrees to radians
    carLat = toRadians(carLat);
    carLng = toRadians(carLng);
    targetLat = toRadians(targetLat);
    targetLng = toRadians(targetLng);

    // Calculate the differences in latitude and longitude
    double deltaLng = targetLng - carLng;

    // Calculate the Forward Azimuth
    double X = cos(targetLat) * sin(deltaLng);
    double Y = cos(carLat) * sin(targetLat) - sin(carLat) * cos(targetLat) * cos(deltaLng);

    // Calculate the initial bearing in radians
    double initialBearing = atan2(X, Y);

    // Convert the initial bearing to degrees
    initialBearing = initialBearing * (180.0 / M_PI);

    // Normalize the bearing
    double waypointAngle = fmod((initialBearing + 360.0), 360.0);

    return waypointAngle;


}
