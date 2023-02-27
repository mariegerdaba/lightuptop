//Store Sensor Values in einem Array, errechnet Durchschnitswert und gibt diesen in Variable aus.


// uint32_t storeValues[200] = {0};

// for(int i = 0; i<200; i++)
// {
//       storeValues[i] += analogRead(A5);  //analog type Temp sensor is connected with A5-pin
//       delay(200);    //delay to avoid cross talk with Pressure channel
//       summe += storeValues[l];
//       average = summe / 200; // float summe?
//       return average
//       i=0;
// }


// Initialize sound sensor
int Analog_Eingang = A5;

// double storeValues[200]; //signed machen? int32 statt uint32?
int storeValues[200]; //signed machen? int32 statt uint32?

int count = 0;
// uint32_t sum = 0; //uint UNSIGNED INTEGER, IMMER POS, int32bit
int avg;
int i; 


void setup() { 
     
  pinMode (Analog_Eingang, INPUT);
  Serial.begin (9600); // Serial output with 9600 bits per second

}


void loop() { 
  // sensorValue = analogRead (Analog_Eingang);

  storeValues[count] = analogRead (Analog_Eingang);

  if (count < 199) {
    count++;
    } else {
    count = 0;

    avg = average(storeValues, 200);
    Serial.println(avg);
    }

}

// int size = 200; 

double average(int arr[], int size) {
  uint32_t sum = 0;                

   for (i = 0; i < size; ++i) {
      sum += arr[i];
   }
   return double(sum) / size;
}


// int average (int arr[],200>) {

//     uint32_t sum = 0;
//     for (let i = 0; i < 200; i++) {
//     sum += arr[i];
//     }

//     return sum / 200;

// }