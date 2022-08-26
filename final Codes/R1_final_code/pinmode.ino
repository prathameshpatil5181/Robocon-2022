void pinmode()
{

  pinMode(stepPin1,OUTPUT);
  pinMode(dirPin1,OUTPUT);
   
  pinMode(dir1, OUTPUT);   //FOR MOTOR
  ledcSetup(ledChannel0, freq, resolution);
  ledcAttachPin(leftfront, ledChannel0);


  pinMode(dir2, OUTPUT);
  ledcSetup(ledChannel1, freq, resolution);
  ledcAttachPin(rightfront, ledChannel1);



  pinMode(dir3, OUTPUT);
  ledcSetup(ledChannel2, freq, resolution);
  ledcAttachPin(leftback, ledChannel2);



   pinMode(dir4, OUTPUT);   //FOR MOTOR
  ledcSetup(ledChannel3, freq, resolution);
  ledcAttachPin(upleft, ledChannel3);

   pinMode(dir5, OUTPUT);   //FOR MOTOR
  ledcSetup(ledChannel4, freq, resolution);
  ledcAttachPin(upright, ledChannel3);
  
}
