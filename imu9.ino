#include "mpu9250.h"

// Create an MPU9250 object with the I2C interface and address 0x68
MPU9250 sensor(Wire, 0x68);

void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for the Serial monitor to open

  // Initialize I2C communication
  Wire.begin();

  // Initialize the MPU9250 sensor
  int status = sensor.begin();
  if (status < 0) {
    Serial.println("MPU9250 initialization failed!");
    Serial.println("Check the wiring or I2C address.");
    while (1); // Halt execution
  }
  Serial.println("MPU9250 initialized successfully.");
}

void loop() {
  // Read data from the sensor
  sensor.readSensor();

  // Print accelerometer data
  Serial.print("Accelerometer X: ");
  Serial.println(sensor.getAccelX_mss(), 2);
  Serial.print("Accelerometer Y: ");
  Serial.println(sensor.getAccelY_mss(), 2);
  Serial.print("Accelerometer Z: ");
  Serial.println(sensor.getAccelZ_mss(), 2);

  // Print gyroscope data
  Serial.print("Gyroscope X: ");
  Serial.println(sensor.getGyroX_rads(), 2);
  Serial.print("Gyroscope Y: ");
  Serial.println(sensor.getGyroY_rads(), 2);
  Serial.print("Gyroscope Z: ");
  Serial.println(sensor.getGyroZ_rads(), 2);

  // Print magnetometer data
  Serial.print("Magnetometer X: ");
  Serial.println(sensor.getMagX_uT(), 2);
  Serial.print("Magnetometer Y: ");
  Serial.println(sensor.getMagY_uT(), 2);
  Serial.print("Magnetometer Z: ");
  Serial.println(sensor.getMagZ_uT(), 2);

  // Print temperature
  Serial.print("Temperature: ");
  Serial.println(sensor.getTemperature_C(), 2);

  Serial.println("------------------------------------");

  // Add a delay
  delay(500);
}
