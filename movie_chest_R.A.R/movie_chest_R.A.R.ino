#include <Servo.h>
Servo myservo[7];
int n=1,j=0,k;
void setup() {
  Serial.begin(9600);
  //myservo[0].attach(3);
  myservo[1].attach(3);//servo 1
  //myservo[2].attach(4);//servo 2 // no use
  myservo[3].attach(5);//servo 3
  myservo[4].attach(6);//servo 4
  myservo[5].attach(7);//servo 5 // base
  myservo[6].attach(8);//servo 6
  /*Initial position */
  myservo[1].write(90);
  //myservo[2].write(90);// no use
  myservo[3].write(180);
  myservo[4].write(120);
  myservo[5].write(180); // base
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
    /*forward*/
  delay(500);
  positioN(180,90,myservo[5],20);
  positioN(180,130,myservo[3],20);
  positioN(120,70,myservo[4],20);
  positioN(90,15,myservo[1],20);
  delay(2000);
  /*reverse*/
  positioN(15,45,myservo[1],20);
  positioN(70,120,myservo[4],20);
  positioN(130,180,myservo[3],20);
  positioN(90,180,myservo[5],20);
  delay(2000);
  }
}
