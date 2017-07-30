#include <dht.h>

dht DHT;

#define DHT11_PIN 7
int soil = A0;
int chk,soilval,motor;
char stat;

void setup(){
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop()
{ 
  if(Serial.available()>0)
    {
      stat = Serial.read();
      if(stat=='o')
        digitalWrite(11,HIGH);
      else if(stat=='c')
        digitalWrite(11,LOW);
    }     
  chk = DHT.read11(DHT11_PIN);
  soilval = analogRead(soil);
  soilval = map(soilval,550,0,0,100);
  Serial.println(DHT.temperature);
  Serial.println(DHT.humidity);
  Serial.println(soilval);
  delay(10000);
}

