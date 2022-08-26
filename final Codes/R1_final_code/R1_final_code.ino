#include <Ps3Controller.h>
#include <math.h>
int runMotor = 1;

int  now = 0;
#define dirPin1 21
#define stepPin1 32
#define piston 25
#define piston2 26

int dir1 = 19; //32
int leftfront = 18; //21

int dir2 = 14; //33
int rightfront = 27; //19

int dir3 = 15; //25
int leftback = 2; //18

int dir4 = 5; //32
int upleft = 17     ; //21

int dir5 = 22; //33
int upright = 23; //19

float Lx , Ly , Rx , Ry ;
int PWM = 255;
int count1 = 800;

const int freq = 5000;

const int ledChannel0 = 0;
const int ledChannel1 = 1;
const int ledChannel2 = 2;
const int ledChannel3 = 3;
const int ledChannel4 = 4;

const int resolution = 8;



void onConnect() {
  Serial.println("Connected.");
}

void setup()
{
  Serial.begin(115200);
  pinMode(piston,OUTPUT);
  pinMode(piston2,OUTPUT);
  //digitalWrite(piston,LOW);
  pinmode();
  // Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("00:1b:10:00:2a:ee");
  //PR address=00:1b:10:00:2a:ee

        digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
      ledcWrite(0, 0);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(1, 0);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 0);

      digitalWrite(dir4, LOW);        //LEFT MOTOR 137
      ledcWrite(3, 0);

digitalWrite(dir5, LOW);        //LEFT MOTOR 137
      ledcWrite(4, 0);

  delay(2000);
      now =millis();

}

void loop()
{
  Rx = Ps3.data.analog.stick.rx;
  Ry = Ps3.data.analog.stick.ry;
  Lx = Ps3.data.analog.stick.lx;
  Ly = Ps3.data.analog.stick.ly;
  //Ps3.setRumble(100.0,1000);
  //PWM=sqrt(sq(Lx)+sq(Ly));
  //Serial.println(PWM);
  //  if(PWM>128){
  //    PWM=128;
  //    }
  //  PWM=(PWM - 0) * (255 - 0) / (128 - 0) + 0;



  /******************************* Constant run motor*********************************************/

  if(runMotor ==0){
  
      digitalWrite(dir4, LOW);        //LEFT MOTOR 137
      ledcWrite(3, 255);

      digitalWrite(dir5, HIGH);        //LEFT MOTOR 137
      ledcWrite(4, 255);
      delay(10);
   
  }

  //selection controlls

  if (-Lx < Ly &&  Lx <= Ly && Ly > 30)                  //ly>=0 && ly<123 && lx==123
  {
    int count = 0;
    while (-Lx < Ly &&  Lx <= Ly && Ly > 30 && count <= PWM) {

      digitalWrite(dir1, LOW);        //LEFT MOTOR 137
      ledcWrite(0, count);

      digitalWrite(dir2, LOW);        //LEFT MOTOR 137
      ledcWrite(1, count);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 0);

      delay(3);
      count++;

      Rx = Ps3.data.analog.stick.rx;
      Ry = Ps3.data.analog.stick.ry;
      Lx = Ps3.data.analog.stick.lx;
      Ly = Ps3.data.analog.stick.ly;
    }
    while (-Lx < Ly &&  Lx <= Ly && Ly > 30) {

      motor(2, PWM);

      Rx = Ps3.data.analog.stick.rx;
      Ry = Ps3.data.analog.stick.ry;
      Lx = Ps3.data.analog.stick.lx;
      Ly = Ps3.data.analog.stick.ly;
    }


    while (count >= 0) {

      digitalWrite(dir1, LOW);        //LEFT MOTOR 137
      ledcWrite(0, count);

      digitalWrite(dir2, LOW);        //LEFT MOTOR 137
      ledcWrite(1, count);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 0);

      count--;
      // motor(2,PWM);                                         //back
      Serial.println("back");
    }
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else if (-Lx <= -Ly &&  Lx < -Ly && Ly < -30)       //ly>123 && ly<=255 && lx==123
  {
    int count = 0;
    while (-Lx <= -Ly &&  Lx < -Ly && Ly < -30 && count <= PWM) {

      digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
      ledcWrite(0, count);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(1, count);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 0);

      delay(3);
      count++;

      Rx = Ps3.data.analog.stick.rx;
      Ry = Ps3.data.analog.stick.ry;
      Lx = Ps3.data.analog.stick.lx;
      Ly = Ps3.data.analog.stick.ly;
    }
    while (-Lx <= -Ly &&  Lx < -Ly && Ly < -30) {

      motor(1, PWM);

      Rx = Ps3.data.analog.stick.rx;
      Ry = Ps3.data.analog.stick.ry;
      Lx = Ps3.data.analog.stick.lx;
      Ly = Ps3.data.analog.stick.ly;
    }


    while (count >= 0) {

      digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
      ledcWrite(0, count);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(1, count);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 0);

      count--;
      // motor(2,PWM);                                         //back
      Serial.println("back");
    }                                         //front
    Serial.println("front");
  }
  else if (Lx > Ly && Lx >= -Ly && Lx > 30)           //lx>123 && lx <= 255 && ly==123
  {
    motor(6, PWM);                                        //RIGHT
    Serial.println("Right");
  }
  else if (-Lx >=  Ly &&  -Lx > -Ly && Lx < -3)       //lx>=0 && lx<123 && ly==123
  {
    motor(7, PWM);                                        //LEFT
    Serial.println("Left");
  }
  else if (-Rx >=  Ry &&  -Rx > -Ry && Rx < -30)     //Rx>=0 && Rx<123 && Ry==123
  {
    motor(4, PWM);                                       //ANTICLOCKWISE
    Serial.println("Anticlockwise");
  }
  else if (Rx > Ry && Rx >= -Ry && Rx > 30 )          //Rx<=255 && Rx<123 && Ry==123
  {
    motor(5, PWM);                                       //CLOCKWISE
    Serial.println("Clockwise");
  }
  else if (Ps3.data.button.r1 )          //Rx<=255 && Rx<123 && Ry==123
  {
    if (PWM == 255) {
      PWM = 127;
    }
    else {
      PWM = 255;
    }
    delay(500 );
  }
else if (Ps3.data.button.square){
 digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 255); 
}
  else if (Ps3.data.button.l1 )          //Rx<=255 && Rx<123 && Ry==123
  {
    if (runMotor == 1) {
      runMotor = 0;
    }
    else {
      runMotor = 1;
    }
    delay(500);
  }
 
  else if (Ps3.data.button.r2 )          //Rx<=255 && Rx<123 && Ry==123
  {
    digitalWrite(piston,HIGH);
    digitalWrite(piston2,HIGH);
    delay(1000);
    digitalWrite(piston,LOW);
    digitalWrite(piston2,LOW);
    delay(500);
  }

// else if ( Ps3.data.button.triangle) {
//      digitalWrite(dirPin1, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(stepPin1, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(stepPin1, LOW);
//      delayMicroseconds(10);
//  }
//
//else if ( Ps3.data.button.cross) {
//      digitalWrite(stepPin1, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(dirPin1, LOW);
//      delayMicroseconds(10);
//      digitalWrite(dirPin1, HIGH);
//  }
 else if ( Ps3.data.button.triangle) {
while(Ps3.data.button.triangle){
      digitalWrite(dirPin1, HIGH);
     // delay(1);
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(800);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(800);
 }
  }

else if ( Ps3.data.button.cross) {
  while(Ps3.data.button.cross){
     digitalWrite(dirPin1, LOW);
      //delay(1);
      
      digitalWrite(stepPin1, HIGH);
      delayMicroseconds(800);
      digitalWrite(stepPin1, LOW);
      delayMicroseconds(800);
 }
 }
  
  
 else
  {
    motor(3, PWM);   
//    digitalWrite(stepPin1,LOW);
//    digitalWrite(dirPin1,LOW);//STOP
    Serial.println("Stop");
  }

  
// if ( Ps3.data.button.triangle) {
//  while(Ps3.data.button.triangle){
//      digitalWrite(dirPin1, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(stepPin1, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(stepPin1, LOW);
//      delayMicroseconds(10);
//  }
//  }
//
// if ( Ps3.data.button.cross) {
//  while(Ps3.data.button.cross){
//      digitalWrite(stepPin1, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(dirPin1, LOW);
//      delayMicroseconds(10);
//      digitalWrite(dirPin1, HIGH);
//      delayMicroseconds(10);
//  }
//  }

}
