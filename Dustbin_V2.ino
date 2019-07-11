#include <Servo.h>   //servo library
//Servo servo1;
Servo servo2;     
int trigPin = 2;    
int echoPin = 3;   
//int servoPin1 = 9;
int servoPin2 = 10;

long duration, dist, average;   
long aver[3];   //array for average


void setup() {       
   // servo1.attach(servoPin1); 
    servo2.attach(servoPin2); 
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
   // servo1.write(0);    
    servo2.write(90);//close cap on power on
    delay(1000);
    //servo1.detach();
    servo2.detach();
} 

void measure() {  
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(50);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    //average distance by 3 measurements

if ( dist<30 ) {
 //if hand on the distance 10...30 cm
 //servo1.attach(servoPin1);
 servo2.attach(servoPin2);
  delay(1);
 //servo1.write(90);  
 servo2.write(0);
 delay(5000);       //wait 5 seconds
 //servo1.write(0);    
  servo2.write(90); 
 delay(1000);
 //servo1.detach();  
servo2.detach();    
}
}
