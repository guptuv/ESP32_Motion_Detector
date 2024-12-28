#include "MPU9250.h"

MPU9250 mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(2000);



    if (!mpu.setup(0x68)) {  
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }
}

void loop() {
    if (mpu.update()) {
        
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            print_roll_pitch_yaw();
            print_acc_x_y_z();
            prev_ms = millis();
        }

        //Linear accln
        float ax = mpu.getAccX();
        float ay = mpu.getAccY();
        float az = mpu.getAccZ();
        float linearAx = ax*9.81; 
        float linearAy = ay*9.81;
        float linearAz = az*9.81; 

        // Angular Acceln
        static float prevGyroX = 0, prevGyroY = 0, prevGyroZ = 0;
        static unsigned long prevTime = millis();
        float gyroX = mpu.getGyroX();
        float gyroY = mpu.getGyroY();
        float gyroZ = mpu.getGyroZ();
        float dt = (millis() - prevTime) / 1000.0;
        float angularAccX = (gyroX - prevGyroX) / dt;
        float angularAccY = (gyroY - prevGyroY) / dt;
        float angularAccZ = (gyroZ - prevGyroZ) / dt;
        prevGyroX = gyroX;
        prevGyroY = gyroY;
        prevGyroZ = gyroZ;
        prevTime = millis();

        // Magnetic Fields
        float magX = mpu.getMagX();
        float magY = mpu.getMagY();
        float magZ = mpu.getMagZ();

       

        Serial.print("Angular Acceleration: ");
        Serial.print(angularAccX); Serial.print(", ");
        Serial.print(angularAccY); Serial.print(", ");
        Serial.println(angularAccZ);

        // Serial.print(angularAccX);
        // Serial.print(angularAccY);
        // Serial.print(angularAccZ);
        // Serial.println();

        Serial.print("Magnetic Field: ");
        Serial.print(magX); Serial.print(", ");
        Serial.print(magY); Serial.print(", ");
        Serial.println(magZ);
        

        

       

        Serial.println("    :)  ");
        delay(1500); 
    }
}
void print_roll_pitch_yaw() {
    Serial.print("Yaw, Pitch, Roll: ");
    Serial.print(mpu.getYaw(), 2);
    Serial.print(", ");
    Serial.print(mpu.getPitch(), 2);
    Serial.print(", ");
    Serial.println(mpu.getRoll(), 2);
  
}

void print_acc_x_y_z() {
    Serial.print("Acc: X, Y, Z: ");
    Serial.print(mpu.getAccX(), 2);
    Serial.print(", ");
    Serial.print(mpu.getAccY(), 2);
    Serial.print(", ");
    Serial.println(mpu.getAccZ(), 2);
}

