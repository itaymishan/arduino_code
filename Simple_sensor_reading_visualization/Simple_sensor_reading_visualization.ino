/**
 * Wiring visual sensor test
 * Simple sensor reading visualization for data interpretation and
 * calibration, shows the last 600 values and prints on serial port
 * current value, minimum value and maximum value. Minimum
 * and maximum can be reset by pressing mouse left button.
 */

import processing.serial.*;
Serial port;
int linefeed = 10;

int[] posX;
int[] posY;

int valMax = 0;
int valMin = 400;

void setup() {
  size(600, 400);

  println(Serial.list());
  port = new Serial(this, Serial.list()[0], 9600);
  port.bufferUntil(linefeed);

  posX = new int[width];
  for (int i=0;i<width;i++) {
    posX[i]=510;
  }

  posY = new int[width];
  for (int i=0;i<width;i++) {
    posY[i]=width-i;
  }
}

void draw() {
  background(25);
  smooth();
  stroke(255, 200);

  if ((posX != null)&&(posY != null)) {
    for (int i=0;i<width-2;i++) {
      line (posY[i], height - map(posX[i], 0, 1024, 0, height), 
      posY[i+1], height - map(posX[i+1], 0, 1024, 0, height));
    }
  }
  
  if(mousePressed){
    valMax = 0;
    valMin = 1024;
  }
}


void serialEvent(Serial port) {
  String myString = port.readStringUntil(linefeed);
  if (myString != null) {
    myString = trim(myString);

    for (int i=width-1;i>0;i--) {
      posX[i]= posX[i-1];
    }
    posX[0] = int(myString);
    if (posX[0] > valMax)
      valMax = posX[0];
    if (posX[0] < valMin)
      valMin = posX[0];
    println(posX[0]+ "  min: "+ valMin+ "  max: "+ valMax);
  }
}
