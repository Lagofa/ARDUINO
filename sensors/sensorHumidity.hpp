#define FCPIN A0

void initSensor() {
    pinMode(FCPIN,INPUT);
}

float getValue(){
  return map(analogRead(FCPIN), 0, 1024, 100, 0);
}
