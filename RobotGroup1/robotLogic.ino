void robotLogic() {
  // Process motor logic based on IR sensor values
  motorLogic();
}

void motorLogic() {
  // The logic to tell the motors how to operate

  int* IRvalues;
  IRvalues = readInfrared();  // Read the current state of the IR sensors

  if (IRvalues[1] == 1 && IRvalues[2] == 1) {
    motorControl(200,200);  // Move the robot forward
  } else if (IRvalues[1] == 0 && IRvalues[2] == 1) {
    motorControl(150, 200);  // Turn slight left
  } else if (IRvalues[1] == 1 && IRvalues[2] == 0) {
    motorControl(200,150);  //Turn slight right
  }
}