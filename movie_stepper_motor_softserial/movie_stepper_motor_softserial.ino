#define EN        8
#define X_STP     2  
#define X_DIR     5
#define Y_STP     3  
#define Y_DIR     6
#define Z_STP     4  
#define Z_DIR     7

#include<String.h>
int delayTime=50; //Delay between each pause (uS) ,speed 
//int stps=10000;// Steps to move 10000 ,no:of steps
int val,i;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13); // RX, TX

void setup(){
  Serial.begin(9600);
  pinMode(X_DIR, OUTPUT); 
  pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); 
  pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT); 
  pinMode(Z_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH); // Deactuating stepper motors, low- on , high-off
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}
void loop(){
   //digitalWrite(EN, LOW); //Actuating stepper motors
  if( mySerial.available() )  
  {
   val = mySerial.read();   
  }
  Serial.println("val:"+String(val));
  /* X STEPPER MOTOR*/
  if( val == '1' )          // Move Forward      
  {
    digitalWrite(EN, LOW); // actuating stepper motors, low- on , high-off
    digitalWrite(X_DIR, true); //direction of stepper motor
    for (i=0 ; i <10000; i++) 
    {
    digitalWrite(X_STP, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(X_STP, LOW);
    delayMicroseconds(delayTime);
    }
  }
  /* Y STEPPER MOTOR */
  if( val == '2' )          // Move Forward      
  {
    digitalWrite(EN, LOW); // actuating stepper motors, low- on , high-off
    digitalWrite(Y_DIR, true); //direction of stepper motor
    for (i=0 ; i <10000; i++) 
    {
    digitalWrite(Y_STP, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(Y_STP, LOW);
    delayMicroseconds(delayTime);
    }
  }
  /* Z STEPPER MOTOR */
  if( val == '3' )          // Move Forward      
  {
    digitalWrite(EN, LOW); // actuating stepper motors, low- on , high-off
    digitalWrite(Z_DIR, true); //direction of stepper motor
    for (i=0 ; i <10000; i++) 
    {
    digitalWrite(Z_STP, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(Z_STP, LOW);
    delayMicroseconds(delayTime);
    }
  }
  /* XY STEPPER MOTOR */
  if( val == '4' )          // Move Forward      
  {
    digitalWrite(EN, LOW);
    digitalWrite(X_DIR, true); //direction of stepper motor
    digitalWrite(Y_DIR, true);
    for (i=0 ; i <10000; i++) 
    {
      digitalWrite(X_STP, HIGH);
    digitalWrite(Y_STP, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(X_STP, LOW);
    digitalWrite(Y_STP, LOW);
    delayMicroseconds(delayTime);
    }
  }
  /* XZ STEPPER MOTOR */
  if( val == '5' )          // Move Forward      
  {
    digitalWrite(EN, LOW);
    digitalWrite(X_DIR, true); //direction of stepper motor
    digitalWrite(Z_DIR, true);
    for (i=0 ; i <10000; i++) 
    {
      digitalWrite(X_STP, HIGH);
    digitalWrite(Z_STP, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(X_STP, LOW);
    digitalWrite(Z_STP, LOW);
    delayMicroseconds(delayTime);
    }
  }
  /* YZ STEPPER MOTOR */
  if( val == '6' )          // Move Forward      
  {
    digitalWrite(EN, LOW);
    digitalWrite(Y_DIR, true); //direction of stepper motor
    digitalWrite(Z_DIR, true);
    for (i=0 ; i <10000; i++) 
    {
      digitalWrite(Y_STP, HIGH);
    digitalWrite(Z_STP, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(Y_STP, LOW);
    digitalWrite(Z_STP, LOW);
    delayMicroseconds(delayTime);
    }
  }
  /* XYZ STEPPER MOTOR */
  if( val == '7' )          // Move Forward      
  {
    digitalWrite(EN, LOW);
    digitalWrite(X_DIR, true); //direction of stepper motor
    digitalWrite(Y_DIR, true);
    digitalWrite(Z_DIR, true);
    for (i=0 ; i <10000; i++) 
    {
     digitalWrite(X_STP, HIGH);
    digitalWrite(Y_STP, HIGH);
    digitalWrite(Z_STP, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(X_STP, LOW);
    digitalWrite(Y_STP, LOW);
    digitalWrite(Z_STP, LOW);
    delayMicroseconds(delayTime);
    }
  }
   /* XYZ STEPPER MOTOR REVERSE */
  if( val == '8' )          // Move Forward      
  {
    digitalWrite(EN, LOW);
    digitalWrite(X_DIR, false); //direction of stepper motor
    digitalWrite(Y_DIR, false);
    digitalWrite(Z_DIR, false);
    for (i=0 ; i <10000; i++) 
    {
     digitalWrite(X_STP, HIGH);
    digitalWrite(Y_STP, HIGH);
    digitalWrite(Z_STP, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(X_STP, LOW);
    digitalWrite(Y_STP, LOW);
    digitalWrite(Z_STP, LOW);
    delayMicroseconds(delayTime);
    }
  }
  else if(val == '0')
  {
    /*digitalWrite(X_STP, LOW);
    digitalWrite(Y_STP, LOW);
    digitalWrite(Z_STP, LOW);
    delayMicroseconds(delayTime); 
    digitalWrite(X_STP, LOW);
    digitalWrite(Y_STP, LOW);
    digitalWrite(Z_STP, LOW);
    delayMicroseconds(delayTime);*/
    digitalWrite(EN, HIGH); // MOTOR OFF
  }
  }
