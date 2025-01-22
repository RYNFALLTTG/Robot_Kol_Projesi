/*
   Данный код плавно управляет одной сервой (на пине 2)
   при помощи потенциометра (на пине А0).
   Откройте порт по последовательному соединению для наблюдения за положением серво
   Документация: https://alexgyver.ru/servosmooth/
*/

#include <ServoSmooth.h>
ServoSmooth servo1;
ServoSmooth servo2;//sağy
ServoSmooth servo3;//sağs
ServoSmooth servo4;//sols
uint32_t myTimer;

void setup() {
  Serial.begin(9600);
  servo1.attach(4, 600, 2400); //kısakaç
  servo2.attach(5, 600, 2400);//na bom
  servo3.attach(6, 600, 2400);
  servo4.attach(7, 600, 2400);//göbek
  
  servo1.setSpeed(300);   
  servo1.setAccel(0.8); 
  servo2.setSpeed(600);  
  servo2.setAccel(0.8);
  servo3.setSpeed(300);  
  servo3.setAccel(0.8);
  servo4.setSpeed(800);  
  servo4.setAccel(1.5);
}

void loop() {

boolean state1 = servo1.tick();   
boolean state2 = servo2.tick();   
boolean state3 = servo3.tick();  
boolean state4 = servo4.tick();  

  if (millis() - myTimer >= 10) {
    myTimer = millis();
    int newPos1 = map(analogRead(A3), 0, 1023, 500, 2400); 
    servo1.setTarget(newPos1);               
    Serial.println(String(newPos1) + " " + String(servo1.getCurrent())/* + " " + String(state)*/);
	
  }
  
  if (millis() - myTimer >= 10) {
    myTimer = millis();
    int newPos2 = map(analogRead(A2), 1023, 0, 500, 2400);
    servo2.setTarget(newPos2);              
    Serial.println(String(newPos2) + " " + String(servo2.getCurrent())/* + " " + String(state)*/);
  
  }
    if (millis() - myTimer >= 10) {
    myTimer = millis();
    int newPos3 = map(analogRead(A1), 1023, 0, 500, 2400); 
    servo3.setTarget(newPos3);             
    Serial.println(String(newPos3) + " " + String(servo3.getCurrent())/* + " " + String(state)*/);
  
  }
    if (millis() - myTimer >= 10) {
    myTimer = millis();
    int newPos4 = map(analogRead(A4), 0, 800, 600, 2400); 
    servo4.setTarget(newPos4);              
    Serial.println(String(newPos4) + " " + String(servo4.getCurrent())/* + " " + String(state)*/);
  
  }
  
}
