int soundsensor = 3;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int led5 = 8;

void setup ()
{
  pinMode (soundsensor,INPUT);
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
  pinMode (led3,OUTPUT);
  pinMode (led4,OUTPUT);
  pinMode (led5,OUTPUT);
}

void loop ()
{
  int sensorvalue = digitalRead (soundsensor);
  if (sensorvalue == 1)
  { 
    digitalWrite(led1,1); // 1 = HIGH 
    digitalWrite(led2,1);
    digitalWrite(led3,1); 
    digitalWrite(led4,1);
    digitalWrite(led5,1); 

}
 

  else (sensorvalue == 0);
  { 
    digitalWrite(led1,0); // 0 = LOW 
    digitalWrite(led2,0);  
    digitalWrite(led3,0); 
    digitalWrite(led4,0);
    digitalWrite(led5,0); 
  }
}
