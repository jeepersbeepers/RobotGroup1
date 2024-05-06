#include <tcs3200.h>

#define IR_1 2
#define IR_2 4
#define IR_3 7
#define IR_4 8

#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

unsigned long irSensorMillis = 0;  // Timer to track the lsat report of the IR sensors

void setup() {
  // Setup Infrared Pins
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
}

void loop() {
  // Get the current run time in milliseconds
  unsigned long currentMillis = millis();

  // Check the states of the IR sensors every 500ms
  if (currentMillis - irSensorsMillis >= 500) {
    irSensorMillis = currentMillis;
    readInfrared();
  }
}
