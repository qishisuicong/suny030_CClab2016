/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo


int photocellPin = 0;
int photocellReading;
float brightness;

void setup() {
  Serial.begin(9600);   
  myservo.attach(9); 
  
}

void loop() {
 
  
  photocellReading = analogRead(photocellPin);
//  photocellReading = 1023 - photocellReading;

  brightness = map(photocellReading,0,1023,0,100);
//  Serial.println(photocellReading);
  Serial.println(brightness); 
  if(brightness <= 10){
    myservo.write(180); 
    delay(15);   
  }else{
    myservo.write(0); 
    delay(15);            
  }
}

