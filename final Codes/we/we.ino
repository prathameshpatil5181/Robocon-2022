#include <Ps3Controller.h>
#include <math.h>

#define stepPin2 19
#define stepPin1 15
#define dirPin1 16
#define dirPin2 18

int dir1 = 25; //32
int leftfront = 13; //21

int dir2 = 33; //33
int rightfront = 14; //19

int dir3 = 32; //25
int leftback = 27; //18

int picMotor = 26;
int picdir =23 ;


float Lx , Ly , Rx , Ry ;
int PWM = 100 ;
int count1 = 800;
const int freq = 5000;
const int ledChannel0 = 0;
const int ledChannel1 = 1;
const int ledChannel2 = 2;
const int ledChannel3 = 3;

const int resolution = 8;



void onConnect() {
  Serial.println("Connected.");
}

void setup()
{
  Serial.begin(115200);
  pinmode();
  // Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("00:1b:10:00:2a:ec");
  //PR address=00:1b:10:00:2a:ee


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
  else if (Ps3.event.button_down.r1 )          //Rx<=255 && Rx<123 && Ry==123
  {
    if (PWM == 255) {
      PWM = 127;
    }
    else {
      PWM = 255;
    }
    delay(500 );
  }

  else if ( Ps3.data.button.square/* && count1 >= 0 && count1 < 1600*/) {

    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, LOW);
    delay(10);
    while ( Ps3.data.button.square /*&& count1 >= 0 && count1 < 1600*/) {
      digitalWrite(stepPin1, HIGH);
      digitalWrite(stepPin2, HIGH);
      delay(1);
      digitalWrite(stepPin1, LOW);
      digitalWrite(stepPin2, LOW);
      delay(1);
      count1++;
      Serial.println(count1);
    }
  }

 else if ( Ps3.data.button.circle /*&& count1 > 0 && count1 <= 1600*/) {
    Serial.println("run");
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, HIGH);
    delay(10);
    while ( Ps3.data.button.circle /* && count1 > 0 && count1 <= 1600*/) {
      digitalWrite(stepPin1, HIGH);
      digitalWrite(stepPin2, HIGH);
      delay(1);
      digitalWrite(stepPin1, LOW);
      digitalWrite(stepPin2, LOW);
      delay(1);
      count1--;
      Serial.println(count1);
    }
  }
  /*********************************************picking mech **************************************************************************/
  else if (Ps3.data.button.triangle)       //ly>123 && ly<=255 && lx==123
  {
    int count = 0;
    while (Ps3.data.button.triangle && count <= PWM) {

      digitalWrite(picdir, HIGH);        //LEFT MOTOR 137
      ledcWrite(3, count);

      delay(3);
      count++;

      Rx = Ps3.data.analog.stick.rx;
      Ry = Ps3.data.analog.stick.ry;
      Lx = Ps3.data.analog.stick.lx;
      Ly = Ps3.data.analog.stick.ly;
    }
    while (Ps3.data.button.triangle) {

     digitalWrite(picdir, HIGH);        //LEFT MOTOR 137
      ledcWrite(3, PWM);

      Rx = Ps3.data.analog.stick.rx;
      Ry = Ps3.data.analog.stick.ry;
      Lx = Ps3.data.analog.stick.lx;
      Ly = Ps3.data.analog.stick.ly;
    }


    while (count >= 0) {

      digitalWrite(picdir, HIGH);        //LEFT MOTOR 137
      ledcWrite(3, count);
      
      count--;
                                        //back
      Serial.println("back");
    }                                         //front
    Serial.println("front");
  }

  else if (Ps3.data.button.cross)       //ly>123 && ly<=255 && lx==123
  {
    int count = 0;
    while (Ps3.data.button.cross && count <= PWM) {

      digitalWrite(picdir, LOW);        //LEFT MOTOR 137
      ledcWrite(3, count);

      delay(3);
      count++;

      Rx = Ps3.data.analog.stick.rx;
      Ry = Ps3.data.analog.stick.ry;
      Lx = Ps3.data.analog.stick.lx;
      Ly = Ps3.data.analog.stick.ly;
    }
    while (Ps3.data.button.cross) {

     digitalWrite(picdir, LOW);        //LEFT MOTOR 137
      ledcWrite(3, PWM);

      Rx = Ps3.data.analog.stick.rx;
      Ry = Ps3.data.analog.stick.ry;
      Lx = Ps3.data.analog.stick.lx;
      Ly = Ps3.data.analog.stick.ly;
    }


    while (count >= 0) {

      digitalWrite(picdir, LOW);        //LEFT MOTOR 137
      ledcWrite(3, count);
      
      count--;
                                        //back
 
    }                                         //front

  }
  /*********************************************picking mech **************************************************************************/ 
  else
  {
    motor(3, PWM);                                    //STOP
    Serial.println("Stop");
  }

//  if ( Ps3.data.button.square/*&&count>=0&&count<1600*/) {
//      Serial.println("run");
//      digitalWrite(dirPin1, HIGH);
//      digitalWrite(dirPin2, LOW);
//      delayMicroseconds(10);
//    while ( Ps3.data.button.square/*&&count>=0&&count<1600*/) {
//      //digitalWrite(dirPin1, HIGH);
//      digitalWrite(stepPin1, HIGH);
//      digitalWrite(stepPin2, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(stepPin1, LOW);
//      digitalWrite(stepPin2, LOW);
//      delayMicroseconds(10);
//      count++;
//      Serial.println(count);
//    }
//  }
//
//else if ( Ps3.data.button.circle/*&&count>0&&count<=1600*/) {
//      Serial.println("run");
//      digitalWrite(dirPin1, LOW);
//      digitalWrite(dirPin2, HIGH);
//      delayMicroseconds(10);
//   // while ( Ps3.data.button.circle/*&&count>0&&count<=1600*/) {
//      //digitalWrite(dirPin1, HIGH);
//      digitalWrite(stepPin1, HIGH);
//      digitalWrite(stepPin2, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(stepPin1, LOW);
//      digitalWrite(stepPin2, LOW);
//      delayMicroseconds(10);
//      //count--;
//      //Serial.println(count);
//    //}
//  }


}
