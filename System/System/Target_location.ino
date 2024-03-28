void target_locaion(){
  
  ble.println("Provide Targeted Gps Location:");
  ble.print("Latitude: ");
  ble.flush();
  while(ble.available() == 0){
  }
  
  if (ble.available() > 0) {
    
    String receivedString = ble.readStringUntil('\n');
    destination_latitude = receivedString.toDouble();
    ble.println(destination_latitude,5);
  
  }
}
