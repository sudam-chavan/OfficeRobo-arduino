#define E1 0  // Enable Pin for motor 1
#define E2 1  // Enable Pin for motor 2

#define I1 2  // Control pin 1 for motor 1
#define I2 3  // Control pin 2 for motor 1
#define I3 4  // Control pin 1 for motor 2
#define I4 5  // Control pin 2 for motor 2

char command[1];
void setup() {
    Serial.begin(57600);
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);

    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
}

void loop() {
  //if (Serial.available() > 0) {
    Serial.readBytes(command, 1);
    if(command[0] == 'F') // Forward
      moveForward();
    if(command[0] == 'B') // Backward
      moveBackward();
    if(command[0] == 'S') // Stop
      stopRobo();
    if(command[0] == 'L') // Left turn
      turnLeft();
     if(command[0] == 'R') // Right turn
      turnRight();
  //}
    // change direction
    //analogWrite(E1, 0);
    //analogWrite(E2, 0);
}

void moveBackward(){
    analogWrite(E1, 255);
    analogWrite(E2, 255);

    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
 }

void moveForward(){
    analogWrite(E1, 255);
    analogWrite(E2, 255);

    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
}

void stopRobo(){
    analogWrite(E1, 0);
    analogWrite(E2, 0);
}

void turnLeft(){
  analogWrite(E2, 255);
  digitalWrite(I3, LOW);
  digitalWrite(I4, HIGH);
  }

void turnRight(){
    analogWrite(E1, 255);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
  }
