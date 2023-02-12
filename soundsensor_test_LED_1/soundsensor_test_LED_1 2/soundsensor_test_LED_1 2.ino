int soundsensor = 3;
int led1 = 4;


void setup ()
{
  pinMode (soundsensor,INPUT);
  pinMode (led1,OUTPUT);
}

void loop ()
{
  int sensorvalue = digitalRead (soundsensor);
  if (sensorvalue == 1)
  { 
    digitalWrite(led1,1); // 1 = HIGH 
  }
 

  else (sensorvalue == 0);
  { 
    digitalWrite(led1,0); // 0 = LOW 
  }
}
