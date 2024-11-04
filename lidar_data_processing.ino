#include <HardwareSerial.h>

// Define the serial port for the LiDAR
HardwareSerial lidarSerial(2);  // Using Serial2 on ESP32

// LiDAR sensor pins
const int lidarRX = 16; // RX to TX of LiDAR sensor
const int lidarTX = 17; // TX to RX of LiDAR sensor

void setup() {
  Serial.begin(115200);              // Serial monitor baud rate
  lidarSerial.begin(115200, SERIAL_8N1, lidarRX, lidarTX); // LiDAR serial baud rate
  Serial.println("ESP32 LiDAR Data Processing Initialized");
}

void loop() {
  if (lidarSerial.available() > 0) {
    int distance = readLidarDistance();
    if (distance != -1) {   // -1 indicates an invalid reading
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      
      // Process distance data here (e.g., threshold check or averaging)
      processDistance(distance);
    }
  }
  delay(100);  // Adjust delay as needed based on sensor specifications
}

// Function to read distance data from LiDAR sensor
int readLidarDistance() {
  // Example protocol: adjust based on your specific LiDAR sensor
  uint8_t buffer[9]; // Adjust the buffer size based on the LiDAR communication protocol
  
  if (lidarSerial.readBytes(buffer, 9) == 9) {
    // Assuming distance data is in bytes 2 and 3 (example: protocol-dependent)
    int distance = (buffer[2] << 8) + buffer[3];
    return distance;
  } else {
    return -1; // Invalid read
  }
}

// Example of processing the distance data
void processDistance(int distance) {
  if (distance < 20) {
    Serial.println("Object detected very close!");
    // Take action if object is too close
  } else if (distance > 200) {
    Serial.println("Object detected far away.");
    // Take action for distant objects
  }
}
