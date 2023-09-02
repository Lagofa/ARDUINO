#include <OneWire.h>                
#include <DallasTemperature.h>
#define DSPIN D5

OneWire ourWire(DSPIN); 
DallasTemperature sensor(&ourWire);

void initSensor() {
  sensor.begin();
}

float getValue(){
  return sensor.getTempCByIndex(0);
}

