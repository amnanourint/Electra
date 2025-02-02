#include <Servo.h>  // Include the Servo library
Servo myServo;

//rain detecting sensor
int TOUCH = 10;
int SERVO = 11;
// human detecting sensor
int IR = 12;
int BUZZ = 13;
//water detect sensor
int FLOAT= 8;
int GLED = 7;
int RLED = 6;
int PUMP = 5;

void setup() {
  myServo.attach(SERVO);
  myServo.write(0);

  pinMode(BUZZ,OUTPUT);
  pinMode(IR,INPUT);
  pinMode(TOUCH,INPUT);
  pinMode(FLOAT,INPUT_PULLUP);
  pinMode(GLED,OUTPUT);
  pinMode(RLED,OUTPUT);
  pinMode(PUMP,OUTPUT);
  digitalWrite(PUMP,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int irvalue = digitalRead(IR);
  int touchvalue = digitalRead(TOUCH);
  int floatvalue = digitalRead(FLOAT);


//human detected
  if (irvalue == LOW){
    digitalWrite(BUZZ,HIGH);
    delay(50);
    digitalWrite(BUZZ,LOW);
    delay(100);
  }else {
    digitalWrite(BUZZ,LOW);
  }

// rain comes
  if (touchvalue == LOW){
    myServo.write(0);
  }else{
    myServo.write(90);
  }
  
//water tank
  if (floatvalue == HIGH){
    digitalWrite(GLED,HIGH);
    digitalWrite(PUMP,LOW);
    digitalWrite(RLED,LOW);
  } else{
    digitalWrite(RLED,HIGH);
    digitalWrite(PUMP,HIGH);
    digitalWrite(GLED,LOW);
  }
}