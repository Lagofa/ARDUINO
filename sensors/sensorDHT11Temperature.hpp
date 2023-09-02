#include <DHT.h>
#define DHTPIN 0
#define DHTTYPE DHT11
 

DHT dht(DHTPIN, DHTTYPE);

void initSensor() {  
  dht.begin();
}

float getValue(){
  return dht.readTemperature();
}
