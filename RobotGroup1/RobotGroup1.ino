#define IR_1 2
#define IR_2 4
#define IR_3 7
#define IR_4 8

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
