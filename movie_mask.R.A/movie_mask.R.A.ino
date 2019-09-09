#include <Servo.h>
Servo myservo[7];
int n=1,j=0,k;
void setup() {
  Serial.begin(9600);
  myservo[1].attach(3);//servo 1
  //myservo[2].attach(4);//servo 2 no use
  myservo[3].attach(5);//servo 3
  myservo[4].attach(6);//servo 4
  myservo[5].attach(7);//servo 5 // base
  /*Initial position */
  myservo[1].write(100);
  //myservo[2].write(180);// no use
  myservo[3].write(180);
  myservo[4].write(90);
  myservo[5].write(90); // base
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
  positioN(180,90,myservo[3],20);
  positioN(100,150,myservo[1],10);
  positioN(90,50,myservo[4],20);
  delay(2000);
  positioN(50,90,myservo[4],20);
  positioN(150,100,myservo[1],10);
  positioN(90,180,myservo[3],20);
  delay(2000);
  }
}
