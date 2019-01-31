import processing.serial.*;

// The serial port:
Serial mySerialPort;       


color fillVal = color(0);

void setup() {
  size(100, 100);
  noStroke();
  background(0);
  printArray(Serial.list()); // do this to find your arduino
  // Open the port you are using at the rate you want:
  mySerialPort = new Serial(this, Serial.list()[1], 115200);
  mySerialPort.clear();
}

void draw() { 
  background(fillVal);
}

//The keyPressed() function is called once every time a key is pressed.
// see https://processing.org/reference/keyCode.html

void keyPressed() {

  if (key == CODED) {
    switch(keyCode) {
    case UP: 
      mySerialPort.write('u');
      break;
    case DOWN: 
      mySerialPort.write('d');
      break;    
    case LEFT: 
      mySerialPort.write('l');
      break;    
    case RIGHT: 
      mySerialPort.write('r');
      break;
    case SHIFT:
      mySerialPort.write('s');
      break;
    case CONTROL:
      mySerialPort.write('c');
      break;
    case ALT:
      mySerialPort.write('a');
      break;
    }
  } else fillVal = color(0);
}

void serialEvent(Serial p) {
  switch(p.read()) {
  case 'R': 
    fillVal = #FF0000;
    break;
  case 'G': 
    fillVal = #00FF00;
    break;    
  case 'Y': 
    fillVal = #FFFF00;
    break;    
  case 'O': 
    fillVal = #FF7F00;
    break;
  case 'B':
    fillVal = #000000;
  default: 
    fillVal = #000000;
    break;
  }
} 
