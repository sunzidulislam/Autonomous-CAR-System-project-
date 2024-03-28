#include <SoftwareSerial.h>

SoftwareSerial bluetooth(4, 3);  // RX, TX pins on Arduino

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);  // Bluetooth module baud rate

  Serial.println("Bluetooth Receiver is ready");
}

void loop() {
  if (bluetooth.available() > 0) {
    // Read a single character
    // char receivedChar = bluetooth.read();
    // Serial.print("Received Char: ");
    // Serial.println(receivedChar);

    // Read a string until a newline character ('\n') is encountered
    String receivedString = bluetooth.readStringUntil('\n');
    Serial.print("Received String: ");
    Serial.println(receivedString);
    
    int intValue = receivedString.toInt();
    Serial.println(intValue);
    bluetooth.println("Received String");
  }

  delay(100);  // Add a small delay for stability
}
