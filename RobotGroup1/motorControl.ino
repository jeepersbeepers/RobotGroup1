// Global speed multipliers for each motor
float motor1Multuiplier = 0.90;
float motor2Multiplier = 1.0;

void motorControl(int speed1, int speed2) {
  // Apply the multipliers to the motor speeds
  int adjustedSpeed1 = speed1 * motor1Multiplier;
  int adjustedSpeed2 = speed2 * motor2Multiplier;

  // Ensure the adjusted speeds do not exceed the PWM range [0, 255]
  adjustedSpeed1 = max(-255, min(255, adjustedSpeed1));
  adjustedSpeed2 = max(-255, min(255, adjustedSpeed2));

  // Apply the adjusted speeds to the motors
  analogWrite(MOTOR_PIN1, adjustedSpeed1 > 0 ? adjustedSpeed1 : 0);
  analogWrite(MOTOR_PIN2, adjustedSpeed1 < 0 ? -adjustedSpeed1 : 0);
  analogWrite(MOTOR_PIN3, adjustedSpeed2 > 0 ? adjustedSpeed2 : 0);
  analogWrite(MOTOR_PIN4, adjustedSpeed2 < 0 ? -adjustedSpeed2 : 0);
}

void loop () {
  // Test motor control by creating a routine that moves
  // the robot forward for 1 second and then turns 90 degrees rigHT.
  // You will have to adjust the delay after the turn to make it a perfect square.
  motorControl(255, 255); // Go straight forward
  delay(1000);
  motorControl(0,0); // Stop momentarily
  delay(100);
  motorControl(255, -255); // Turn to the Right
  delay(500);
  motorControl(0, 0); // Stop momentarily
  delay(100);
}