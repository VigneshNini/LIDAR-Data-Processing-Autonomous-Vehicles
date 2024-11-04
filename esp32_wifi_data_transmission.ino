#include <WiFi.h>
#include <HTTPClient.h>

// Wi-Fi credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Server endpoint (replace with your server URL)
const char* serverName = "http://yourserver.com/data";

// Variables to store data (e.g., sensor readings)
float temperature = 0.0;
float humidity = 0.0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Prepare data (for example, get sensor data here)
    temperature = readTemperature();
    humidity = readHumidity();

    // Construct data payload
    String postData = "temperature=" + String(temperature) + "&humidity=" + String(humidity);

    // Send HTTP POST request
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST(postData);
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.print("Server Response: ");
      Serial.println(response);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("Wi-Fi not connected");
  }

  delay(10000);  // Send data every 10 seconds
}

float readTemperature() {
  // Placeholder function to simulate temperature reading
  return random(20, 30);  // Simulated temperature in Celsius
}

float readHumidity() {
  // Placeholder function to simulate humidity reading
  return random(40, 60);  // Simulated humidity in percentage
}
