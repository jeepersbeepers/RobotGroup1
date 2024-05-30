tcs3200 tcs(COLOR_0, COLOR_1, COLOR_2, COLOR_3, COLOR_OUT);

int avgRed = 0;
int avgGreen = 0;
int avgBlue = 0;
int avgWhite = 0;

String LEDcolor = "Empty";

void readColorSensor() {
  const int samples = 5;
  long sumRed = 0, sumGreen = 0, sumBlue = 0, sumWhite = 0;

  for (int i = 0; i < samples; i++) {
    sumRed += tcs.colorRead('r');
    sumGreen += tcs.colorRead('g');
    sumBlue += tcs.colorRead('b');
    sumWhite += tcs.colorRead('c');
  }

  avgRed = sumRed / samples;
  avgGreen = sumGreen / samples;
  avgBlue = sumBlue / samples;
  avgWhite = sumWhite / samples;

  Serial.print("Average Color Sensor Readings: ");
  Serial.print(" R= ");
  Serial.print(avgRed);
  Serial.print(" G= ");
  Serial.print(avgGreen);
  Serial.print(" B= ");
  Serial.print(avgBlue);
  Serial.print(" W(clear)= ");
  Serial.println(avgWhite);
}

void detectColor(int targetRed, int targetGreen, int targetBlue, int redThreshold, int greenThreshold, int blueThreshold) {
  // Check if the average values are within the specified thresholds for detecting the color
  if (avgRed >= (targetRed - redThreshold) && avgRed <= (targetRed + redThreshold) && avgGreen >= (targetGreen - greenThreshold) && avgGreen <= (targetGreen + greenThreshold) && avgBlue >= (targetBlue - blueThreshold) && avgBlue <= (targetBlue + blueThreshold)) {

    // Determine the detected color based on the target RGB values and print the result
    if (targetRed > targetGreen && targetRed > targetBlue) {
      Serial.println("Color Detected: Red");
      LEDcolor = "Red";
    } else if (targetGreen > targetRed && targetGreen > targetBlue) {
      Serial.println("Color Detected: Green");
      LEDcolor = "Green";
    } else if (targetBlue > targetRed && targetBlue > targetGreen) {
      Serial.println("Color Detected: Blue");
      LEDcolor = "Blue";
    } else if (targetRed > targetGreen && targetGreen > targetBlue && targetRed > targetBlue) {
      Serial.println("Color Detected: Yellow");
      LEDcolor = "Yellow";
    } else {
      Serial.println("Color Not Detected");
    }
  } 

  if (LEDcolor = "Red") {
    WiFiDrv::analogWrite(25, 0);  //GREEN
    WiFiDrv::analogWrite(26, 255);  //RED
    WiFiDrv::analogWrite(27, 0);  //BLUE
  } else if (LEDcolor = "Green") {
    WiFiDrv::analogWrite(25, 255);  //GREEN
    WiFiDrv::analogWrite(26, 0);  //RED
    WiFiDrv::analogWrite(27, 0);  //BLUE
  } else if (LEDcolor = "Blue") {
    WiFiDrv::analogWrite(25, 0);  //GREEN
    WiFiDrv::analogWrite(26, 0);  //RED
    WiFiDrv::analogWrite(27, 255);  //BLUE
  } else if (LEDcolor = "Yellow") {
    WiFiDrv::analogWrite(25, 255);  //GREEN
    WiFiDrv::analogWrite(26, 255);  //RED
    WiFiDrv::analogWrite(27, 0);  //BLUE
  } else {
    WiFiDrv::analogWrite(25, 255);  //GREEN
    WiFiDrv::analogWrite(26, 255);  //RED
    WiFiDrv::analogWrite(27, 255);  //BLUE
  }
}