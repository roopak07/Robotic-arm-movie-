#include <Servo.h>
Servo myservo[5];
int n=0,j=0,k;
void setup() {
  Serial.begin(9600);
  //myservo[0].attach(3);
  myservo[1].attach(2);//servo 1
  myservo[2].attach(3);//servo 2
  myservo[3].attach(4);//servo 3
  myservo[4].attach(5);//servo 4
  myservo[5].attach(9);//servo 5
  myservo[6].attach(7);//servo 6
  /*Initial position */
  myservo[1].write(90);
  myservo[2].write(90);
  myservo[3].write(90);
  myservo[4].write(90);
  myservo[5].write(90);
  myservo[6].write(90);
  //positioN(90,135,myservo[6],50);
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
 /* for(j;j<=n;j++)
  {
  delay(500);
  positioN(180,90,myservo[4],50);
  //positioN(90,45,myservo[3],50);
  //positioN(180,145,myservo[2],50);
  for(k=90;k>=45;k--)
  {
    myservo[3].write(k);
    delay(20);
    if(k>=55)
    {
      
      myservo[2].write(k+90);
      delay(20);
    }
  }
  positioN(135,90,myservo[6],50);
  }*/
}
