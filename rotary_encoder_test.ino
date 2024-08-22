#include "rotary_encoder.cpp"

const int sensorPinL = 3;
const int sensorPinR = 4;


RotaryEncoder encoderL(sensorPinL, 36, 5);;
RotaryEncoder encoderR(sensorPinR, 36, 5);

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  // update very often since serial print has bad performance and is lagging
   for(int i = 0; i < 1000; i++)
   {
     encoderL.Update();
     encoderR.Update();
   }
   if(encoderL.peekCountDelta() > 0 || encoderR.peekCountDelta() > 0)
   {
     Serial.print("Left: ");
     Serial.print(encoderL.getCount());
     Serial.print(" (");
     Serial.print(encoderL.getRounds());
     Serial.print("/");
     Serial.print(encoderL.getSteps());
     Serial.print(")");
     Serial.print("   |    Right: ");
     Serial.print(encoderR.getCount());
     Serial.print(" (");
     Serial.print(encoderR.getRounds());
     Serial.print("/");
     Serial.print(encoderR.getSteps());
     Serial.print(")");
  
     Serial.println();
   }
 
}





























/**
const int sensor = 3;
int counter;

int diskLines = 36;

int sensorHistory = 0;
int historyThreshold = 5;

bool lastResult = false;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
}

void loop() 
{
   
  bool result = measure();
  if(!lastResult && result)
  {
    counter += 1;
    Serial.print("Counter ");
    Serial.println(counter);

    if(counter % diskLines == 0)
    {
      Serial.print("Round ");
      Serial.println( counter / diskLines);
    }
  }
  lastResult = result;

 
  
}


bool measure()
{
  while(true)
  {
    bool measurement = digitalRead(sensor);

    sensorHistory += measurement ? 1 : -1;
    
    if(sensorHistory >= historyThreshold)
    {
      // enough 1's measured to count this one
      sensorHistory = 0;
      return 1;
    }
    else if (sensorHistory < -historyThreshold)
    {
      // enough 0's measured to count this one
      sensorHistory = 0;
      return 0;
    }
  }
}
*/
