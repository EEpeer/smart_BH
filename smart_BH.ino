#include "config.h"

#define Lights 14
#define Door 13
#define bell 12

AdafruitIO_Feed *analog = io.feed("Analog lights");
AdafruitIO_Feed *digital = io.feed("digital");

bool current = false;
bool last = false;

void setup() {
 io.connect();
 
 pinMode(Door, INPUT);
 pinMode(bell, OUTPUT);
  
}


void loop(){
  io.run();

  analog->onMessage(handleMessage);

  if(digitalRead(Door) == LOW)
    current = true;
       
  else
    current = false;
    

  if(current == last)
   return;

  digital->save(current);

  last = current;
   
  delay(100);
}

void handleMessage(AdafruitIO_Data *data){
  int reading = data->toInt();
  analogWrite(Lights, reading);
  
}

