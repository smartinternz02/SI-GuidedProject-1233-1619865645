#include<Servo.h>
Servo myservo;
int trigpin=7;
int echopin=5;
void setup()
{
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9000);
  myservo.attach(4);
}

void loop()
{
  digitalWrite(trigpin,HIGH);
  delay(1000);
   digitalWrite(trigpin,LOW);
  int duration=pulseIn(echopin,HIGH);
  int distance=(duration*0.034)/2;
  Serial.print("the distance of the car is");
  Serial.println(distance);
  if(distance<50)
  {
    myservo.write(0);
  Serial.println("servo is at angle 0");
  delay(1000);
   myservo.write(90);
  Serial.println("servo is at angle 90");
  delay(1000);
   myservo.write(180);
  Serial.println("servo is at angle 180");
  delay(1000);
   myservo.write(0);
  Serial.println("servo is at angle 0");
  delay(1000);
}
  else
  {
    digitalWrite(trigpin,LOW);
  }
  delay(1000);
}
