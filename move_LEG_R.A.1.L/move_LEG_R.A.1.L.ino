#include <Servo.h>
Servo myservo[7];
int n=1,j=0,k;
void setup() {
  Serial.begin(9600);
  //myservo[0].attach(3);
  myservo[1].attach(2);//servo 1
  myservo[2].attach(3);//servo 2 
  myservo[3].attach(4);//servo 3
  myservo[4].attach(5);//servo 4
  myservo[5].attach(6);//servo 5 // base
  myservo[6].attach(7);//servo 6
  /*Initial position */
  myservo[1].write(90);
  myservo[2].write(50);
  myservo[3].write(170);
  myservo[4].write(180);
  myservo[5].write(120); 
  myservo[6].write(20);// base
}

void positioN(int prev,int need,Servo servo,int Time)
{
  if(prev > need)
  {
    for(int i=prev;i>=need;i--)
    {
      servo.write(i);
      delay(Time);
    }
  }
  if(prev < need)
  {
    for(int i= prev;i<=need;i++)
    {
      servo.write(i);
      delay(Time);
    }
  }
}
void loop() {
  /*one moment code for six servo robotic arm*/
  for(j;j<=n;j++)
  {
   //forward
  delay(500);
  positioN(20,120,myservo[6],20);
  positioN(180,160,myservo[4],20);
  positioN(90,140,myservo[1],20);
  positioN(120,40,myservo[5],20);
  delay(2000);
  //reverse
  //positioN(15,45,myservo[1],50);
  positioN(40,120,myservo[5],20);
  positioN(160,180,myservo[4],20);
  positioN(120,20,myservo[6],20);
  positioN(140,90,myservo[1],20);
   // deativating servo to overcome over heat
  delay(2000);
  }
  myservo[1].detach();
}
