#include <Servo.h>
Servo myservo[7];
int n=1,j=0,k;
void setup() {
  Serial.begin(9600);
  //myservo[0].attach(3);
  myservo[1].attach(4); //servo 1
  myservo[2].attach(5);//servo 2
  myservo[3].attach(6);//servo 3
  myservo[4].attach(7);//servo 4
  myservo[5].attach(8);//servo 5 // no use
  myservo[6].attach(3); // servo 0
  /*Initial position */
  myservo[6].write(45);
  myservo[1].write(90);
  myservo[2].write(180);
  myservo[3].write(90);
  myservo[4].write(180);
  myservo[5].write(90);
  positioN(90,135,myservo[6],20);
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
  delay(500);
  positioN(180,90,myservo[4],20);
  //positioN(90,45,myservo[3],50);
  //positioN(180,145,myservo[2],50);
  /*two servo coding*/
  for(k=90;k>=45;k--)
  {
    myservo[3].write(k);
    delay(15);
    if(k>=55)
    {
      
      myservo[2].write(k+90);
      delay(15);
    }
  }
  positioN(135,90,myservo[6],20);
  delay(2000);// movement 1 dealy
  /*reverse */
  positioN(90,150,myservo[6],20);
  //positioN(45,90,myservo[3],50);
  //positioN(145,180,myservo[2],50);
  for(k=45;k<=90;k++)
  {
    myservo[3].write(k);
    delay(15);
    if(k<=80)
    {
      
      myservo[2].write(k+100);
      delay(15);
    }
  }
  positioN(90,180,myservo[4],20);
  positioN(90,110,myservo[3],20);
  delay(2000);
  }
}
