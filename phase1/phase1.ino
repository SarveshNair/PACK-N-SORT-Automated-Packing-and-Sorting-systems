#include <Servo.h>
#include <SoftwareSerial.h>

// Pin Definitions
const int MOTOR_IN1 = 2; // Motor driver IN1
const int MOTOR_IN2 = 3; // Motor driver IN2
const int MOTOR_ENABLE = 9; // Motor Enable pin (PWM control)
const int SERVO_PINS[] = {5, 6, 7, 8}; // Servo motor pins
const int QR_RX_PIN = 10; // QR scanner TX
const int QR_TX_PIN = 11; // QR scanner RX

Servo servos[4];          // Array for the 4 servos
SoftwareSerial qrSerial(QR_RX_PIN, QR_TX_PIN); // SoftwareSerial for QR scanner

unsigned long motorStartTime;
bool motorRunning = true;

void setup() {
  Serial.begin(9600);      // Initialize Serial Monitor
  qrSerial.begin(9600);    // Initialize QR scanner communication
  
  // Initialize motor driver pins
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_ENABLE, OUTPUT);
  
  // Start the motor
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_ENABLE, 255); // Full speed
  motorStartTime = millis(); // Record start time
  
  // Attach servos
  for (int i = 0; i < 4; i++) {
    servos[i].attach(SERVO_PINS[i]);
    servos[i].write(0); // Set all servos to 0° initially
  }

  Serial.println("System Initialized");
}

void loop() {
  // Check if 20 seconds have passed
  if (motorRunning && millis() - motorStartTime >= 20000) {
    // Stop the motor
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    analogWrite(MOTOR_ENABLE, 0); // Disable motor
    motorRunning = false;
    Serial.println("Motor Stopped. QR Scanner Active.");
  }

  // If motor is stopped, start QR scanning
  if (!motorRunning && qrSerial.available()) {
    String qrData = qrSerial.readStringUntil('\n'); // Read QR data
    qrData.trim(); // Remove extra whitespace or newline characters

    Serial.print("QR Code Scanned: ");
    Serial.println(qrData);

    // Set servos based on QR code
    if (qrData == "QR1") {
      setServos(0); // Set servos to 0°
    } else if (qrData == "QR2") {
      setServos(-45); // Set servos to -45°
    } else if (qrData == "QR3") {
      setServos(45); // Set servos to 45°
    } else {
      Serial.println("Unknown QR Code. No action taken.");
    }
  }
}

// Function to set all servos to a specific angle
void setServos(int angle) {
  for (int i = 0; i < 4; i++) {
    servos[i].write(90 + angle); // Adjust for neutral position (90°)
  }
  Serial.print("Servos set to ");
  Serial.print(angle);
  Serial.println("°");
}
