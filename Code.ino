//DHT11 Setup 
#include <Adafruit_Sensor.h> 
#include <DHT.h> 
#include <DHT_U.h> 
#define DHTPIN 10     // Digital pin connected to the DHT sensor  
#define DHTTYPE    DHT11  
DHT_Unified dht(DHTPIN, DHTTYPE); 
uint32_t delayMS; 
int temp,hum; 
// GPS Setup 
#include <SoftwareSerial.h> 
#include <TinyGPSPlus.h> 
#define GPS_TX_PIN 2// Define the serial pins for GPS module 
#define GPS_RX_PIN 3// Define the serial pins for GPS module 
TinyGPSPlus gps;// Initialize the GPS object 
SoftwareSerial gpsSerial(GPS_TX_PIN, GPS_RX_PIN);// Initialize the software 
serial for GPS module 
float Lat,Lon,Alt; 
 
//Gas Sensor 
const int gasSensorPin = A0;// Pin definitions 
const int gasR0 = 10000; // Resistance of the sensor in clean air Gas sensor 
settings 
const float gasRatio = 3.57; // Ratio of RS/R0 for CO gas 
float ppm; 
 
//Fall Detection Using MPU6050 
#include <Adafruit_MPU6050.h> 
//#include <Adafruit_Sensor.h> 
#include <Wire.h> 
Adafruit_MPU6050 mpu;// Initialize MPU6050 sensor 
// Threshold values for fall detection 
const float gyro_threshold = 8.0;    // degrees per second 
int fall; // Flag variable to detect fall 
 
 
//Data Packet 
String dp=""; 
 
void setup() { 
   Serial.begin(115200); // Initialize the serial monitor 
  gpsSerial.begin(9600); // Initialize the GPS serial communication 
  mpu.begin(); 
 // Initialize MPU6050 sensor 
// 
//  if (!mpu.begin()) { 
//    Serial.println("Failed to initialize MPU6050 sensor!"); 
//    while (1); 
//  } 
//  mpu.setAccelerometerRange(MPU6050_RANGE_16_G); // Set sensor range to +/- 
16g for accelerometer 
//  mpu.setGyroRange(MPU6050_RANGE_500_DEG);  // Set sensor range to +/- 500 
degrees per second for gyroscope 
//  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ); // Set sensor bandwidth to 5Hz 
for accelerometer and 10Hz for gyroscope 
} 
 
void loop()  
{   
   
   fall=0; 
 
//GPS 
    Lat=12.9165; 
    Lon=79.1325; 
    Alt=237; 
//  while (gpsSerial.available() > 0) { 
//    gps.encode(gpsSerial.read()); 
//     if (gps.location.isValid() && gps.altitude.isValid())  
//     { 
//    Lat=gps.location.lat(); 
//    Lon=gps.location.lng(); 
//    Alt=gps.altitude.meters(); 
//     } 
//Gas Sensor        
int sensorValue = analogRead(gasSensorPin);  // Read gas sensor value 
       float gasRatioValue = (1023.0 / sensorValue) - 1.0; // Calculate gas 
concentration 
       ppm = gasRatioValue / gasRatio * gasR0; // Calculate gas concentration 
 
        //ppm=10; 
 
 
//Fall Detection 
   
//  sensors_event_t a, g, temp;// Read accelerometer and gyroscope data 
//  mpu.getEvent(&a, &g, &temp);// Read accelerometer and gyroscope data 
//  float gyro_mag = sqrt(pow(g.gyro.x, 2) + 
//                        pow(g.gyro.y, 2) +  // Calculate gyroscope magnitude 
//                        pow(g.gyro.z, 2)); 
//  if ( gyro_mag > gyro_threshold) { 
//    fall = 1; 
//  } 
//Temperature and Humidity 
 dht.begin(); 
 sensor_t sensor; 
 sensors_event_t event; 
 dht.temperature().getEvent(&event); 
 temp = event.temperature; 
 dht.humidity().getEvent(&event); 
 hum = event.relative_humidity; 
// temp=31; 
// hum=62; 
//Data Packet 
dp=String(Lat) + "," + String(Lon) + "," + String(Alt) + "," + String(ppm)+ "," 
+ String(temp)+ "," + String(hum) + "," + String(fall); // String Data Packlet 
Creation 
Serial.println(dp); 
delay(1000); 
  }
