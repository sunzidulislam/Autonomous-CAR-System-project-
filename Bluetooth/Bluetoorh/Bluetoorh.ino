#include <SoftwareSerial.h>

SoftwareSerial bluetooth(7, 6);  // RX, TX pins on Arduino

void setup() {
  Serial.begin(9600);
     // Bluetooth module baud rate

  Serial.println("Bluetooth Receiver is ready");
}

void loop() {
  if (bluetooth.available() > 0) {
    
    String receivedString = bluetooth.readStringUntil('\n');
    Serial.print("Received String: ");
    Serial.println(receivedString);
    Serial.print("The integer: ");

    int intValue = receivedString.toInt();
    intValue++;
    Serial.println(intValue);

    float floatValue = receivedString.toFloat();
    floatValue = floatValue+2;
    Serial.print("The float: ");
    Serial.println(floatValue,5);

    double doubleValue = receivedString.toDouble();
    doubleValue = doubleValue+2;
    Serial.print("The Double: ");
    Serial.println(doubleValue,6);

  }

  delay(100);  
}
