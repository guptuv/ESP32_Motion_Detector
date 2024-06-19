# ESP32_Motion_Detector
This Arduino code reads sensor data from an MPU6050 sensor connected to an ESP32 microcontroller board.



Acceleration: Movement along the X, Y, and Z axes (in g-force)
Rotation: Angular velocity around the X, Y, and Z axes (in degrees per second)
This code:

Initializes serial communication between the ESP32 and your computer at a baud rate of 115200.
Initializes the MPU6050 sensor and checks for successful connection.
Continuously reads sensor data in a loop:
Acceleration on the X-axis (g-force)
Rotation (gyroscope) on the X-axis (degrees per second)
Prints the sensor readings to the serial monitor.
Applications:

This code can be a starting point for various projects that utilize motion sensing, such as:

Motion detection: Detect movement or orientation changes.
Balance and stability applications: Monitor tilt and balance.
Gesture recognition: Recognize specific movements based on sensor data.
Data logging: Record sensor data for analysis.
Note:

This code currently only reads and prints data from the X-axis for acceleration and gyroscope. You can modify it to access data from all three axes (X, Y, Z).
Feel free to modify and extend this code for your specific project requirements!
Setup done
![image](https://github.com/guptuv/ESP32_Motion_Detector/assets/116263507/3beb5457-6cda-493c-8ef2-fbfd2c2d319a)

Some resuls on Wokwi
1.
![image](https://github.com/guptuv/ESP32_Motion_Detector/assets/116263507/b073072b-b836-4c79-8f56-32ac5a874961)
<br>
2.
![image](https://github.com/guptuv/ESP32_Motion_Detector/assets/116263507/64d3d08e-9177-4a3d-8c5a-1f7d00e3d550)

Applications:

This code can be a starting point for various projects that utilize motion sensing, such as:

Motion detection: Detect movement or orientation changes.
Balance and stability applications: Monitor tilt and balance.
Gesture recognition: Recognize specific movements based on sensor data.
Data logging: Record sensor data for analysis.
Note:

This code currently only reads and prints data from the X-axis for acceleration and gyroscope. You can modify it to access data from all three axes (X, Y, Z).
Feel free to modify and extend this code for your specific project requirements!
