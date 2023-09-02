#define LDRPIN A0

void initSensor() {
  pinMode(LDRPIN,INPUT);
}

float getValue(){ 
  return analogRead(LDRPIN);
}


