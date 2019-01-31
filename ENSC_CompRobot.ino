int rightMotor = 11;
int leftMotor = 10;
int damMotor = 3;
int Ddown = 200;
int Dup = 90;
int Rforward = 90;
int Lbackward = 90;
int Rbackward = 250;
int Lforward = 250;
int stopMoving = 190;
//185-190 is stop
//90 fast clockwise
//240 fast reverse

void setup() {
  Serial.begin(115200); // make sure it's the same on both sides
  pinMode(rightMotor, OUTPUT);
  pinMode(leftMotor, OUTPUT);
}

void up()
{
  Serial.write('R');  // RED
  analogWrite(rightMotor, Rforward);
  analogWrite(leftMotor, Lforward);
}

void down()
{
  Serial.write('G');  // GREEN
  analogWrite(rightMotor, Rbackward);
  analogWrite(leftMotor, Lbackward);
}

void left()
{
  Serial.write('Y');  // YELLOW
  analogWrite(rightMotor, Rforward);
  analogWrite(leftMotor, Lbackward);
}

void right()
{
  Serial.write('O');  // ORANGE
  analogWrite(rightMotor, Rbackward);
  analogWrite(leftMotor, Lforward);
}

void stophard(){
  Serial.write('B');  // BLACK
  analogWrite(rightMotor, 0);
  analogWrite(leftMotor, 0);
  analogWrite(damMotor, 0);
}

void damUp(){
  Serial.write('R');  // RED
  analogWrite(damMotor, 200);
}

void damDown(){
  Serial.write('G');  // GREEN
  analogWrite(damMotor, 180);
}

void loop() {
  char incomingChar = 0;   // for incoming serial data

  if (Serial.available() > 0) {
    incomingChar = Serial.read();
    switch (incomingChar) {
      case 'u':
        up();
        break;
      case 'd':
        down();
        break;
      case 'l':
        left();
        break;
      case 'r':
        right();
        break;
      case 'c':
        damUp();
        break;
      case 'a':
        damDown();
        break;
      case 's':
        stophard();
        break;
      default:
        Serial.write('B');  // BLACK
        break;
    }
  } else incomingChar = 0; // not really needed but in case you want to do things in the loop upon receiving new chars. if (incomingChar == 0) then no new char was received, otherwise later in the loop you still have the char received
}
