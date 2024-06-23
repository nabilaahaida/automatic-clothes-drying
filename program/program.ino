#include <AccelStepper.h>
#include <Servo.h>
#define motorPin1 8
#define motorPin2 9
#define motorPin3 10
#define motorPin4 11
#define MotorInterfaceType 8


Servo dservo;
int x=0;
int cahaya=A1;
int air=A2;
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);
void setup() {
  dservo.attach(7);
  stepper.setMaxSpeed(600);
  stepper.setAcceleration(800);
  Serial.begin(9600);  
  pinMode(cahaya,INPUT);
  pinMode(air,INPUT);
}


void loop() {
  int data_cahaya=analogRead(cahaya);
  Serial.println(data_cahaya);
  delay(1000);
  int data_air=analogRead(air);
  Serial.println(data_air);
  delay(1000);
  
  if((data_cahaya<=170)&&(data_air>=1000)) {
    delay(1700);
    stepper.runToNewPosition(8200);
  }
  
  else if((data_cahaya>=170)&&(data_air<=900)) {
    stepper.runToNewPosition(0);
    delay(5000);
  }


}
