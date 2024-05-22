#include <tcs3200.h>
#include <WiFiNINA.h>

// State Logic
String currentState = "Null";
String oldCurrentState = "Null";

#define IR_1 4
#define IR_2 7
#define IR_3 8
#define IR_4 12

#define MOTOR_PIN1 3
#define MOTOR_PIN2 5
#define MOTOR_PIN3 6
#define MOTOR_PIN4 9

#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

#define TRIG_PIN 10
#define ECHO_PIN 11

#define LED_R 25
#define LED_G 26
#define LED_B 27

long currentDistance = 0;

unsigned long irSensorMillis = 0;  // Timer to track the last report of the IR sensors

unsigned long currentMillis;
unsigned long colorSensorMillis = 0;  //Timer to track the last report of the color sensors

// Turning Logic
String turnDirection = "";      // Keep track of the current turn direction.
String lastTurnDirection = "";  // Store the last turn direction to decide the next turn if sharp turn is detected.
bool isTurning = false;         // Flag to show if the robot is turning or not.
bool wallDetected = false;      //  Flag to show if the robot has detected a wall with the ultrasonic sensor

void setup() {
  Serial.begin(115200);

  // Setup Infrared Pins
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);

  // Setup Motor Pins
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_PIN3, OUTPUT);
  pinMode(MOTOR_PIN4, OUTPUT);

  // Setup Ultrasonic Sensor Pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Setup WifiDRV
  WiFiDrv::pinMode(LED_R, OUTPUT);  // define GREEN LED
  WiFiDrv::pinMode(LED_G, OUTPUT);  // define RED LED
  WiFiDrv::pinMode(LED_B, OUTPUT);  // define BLUE LED
}

void loop() {
  // Run the robot Logic
  robotLogic();

  // Ultrasonic sensor running
  readUltrasonicSensor();

  // Get the current run time in milliseconds
  currentMillis = millis();

  // Check the states of the IR sensors every 500ms
  if (currentMillis - irSensorMillis >= 500) {
    irSensorMillis = currentMillis;
    readInfrared();
  }

  // Read the color sensor
  if (currentMillis - colorSensorMillis >= 250) {
    colorSensorMillis = currentMillis;
    readColorSensor();
  }

  // Setup onboard RGB LED pins
  WiFiDrv::analogWrite(25, 255);  //GREEN
  WiFiDrv::analogWrite(26, 255);  //RED
  WiFiDrv::analogWrite(27, 255);  //BLUE

}
