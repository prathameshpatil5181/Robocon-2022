void motor(int condn, int PWM)
{
  switch (condn)
  {

    case 1:       //forward

      Serial.println("forward");

      digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
      ledcWrite(0, PWM);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(1, PWM);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 0);

      break;


    case 2:     //backward

      Serial.println("backward");


      digitalWrite(dir1, LOW);        //LEFT MOTOR 137
      ledcWrite(0, PWM);

      digitalWrite(dir2, LOW);        //LEFT MOTOR 137
      ledcWrite(1, PWM);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 0);

      break;

    case 3:     //STOP

      Serial.println("stop");


      digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
      ledcWrite(0, 0);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(1, 0);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 0);


      break;

    case 4:     //rotate CLOCK

      Serial.println("TR");

      digitalWrite(dir1, LOW);        //LEFT MOTOR 137
      ledcWrite(0, PWM);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(1, PWM);

      digitalWrite(dir3, LOW);        //LEFT MOTOR 137
      ledcWrite(2, PWM);

      break;

    case 5:       //rotate

      Serial.println("rotate");


      digitalWrite(dir1, HIGH);       //LEFT MOTOR 137
      ledcWrite(0, PWM);

      digitalWrite(dir2, LOW);        //LEFT MOTOR 137
      ledcWrite(1, PWM);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, PWM);

      break;

    case 6:        //Right

//      Serial.println("RIGHT");
//
//      digitalWrite(dir1, LOW);        //LEFT MOTOR 137
//      ledcWrite(0, PWM);
//
//      digitalWrite(dir2, LOW);        //LEFT MOTOR 137
//      ledcWrite(1, PWM);
//
//      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
//      ledcWrite(2, PWM);

      break;

    case 7 :        //left

      Serial.println("LEFT");

      digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
      ledcWrite(0, PWM);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(1, PWM);

      digitalWrite(dir3, LOW);        //LEFT MOTOR 137
      ledcWrite(2, PWM);


      break;

    case 8:     //STOP

      Serial.println("stop");


      digitalWrite(dir1, HIGH);        //LEFT MOTOR 137
      ledcWrite(0, 0);

      digitalWrite(dir2, HIGH);        //LEFT MOTOR 137
      ledcWrite(1, 0);

      digitalWrite(dir3, HIGH);        //LEFT MOTOR 137
      ledcWrite(2, 0);

      break;

  }
}
