int readUltrasonicSensor() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  long duration = pulseIn(ECHOPIN, HIGH);

  // Calculate distance in centimeters
  int distance = duration * 0.034 / 2;

  // Serial.print("Distance: ");
  // Serial.print(distance);
  // Serial.println(" cm");

  currentDistance = distance;
}