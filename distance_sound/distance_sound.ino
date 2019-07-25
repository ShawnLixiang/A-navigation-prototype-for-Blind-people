/*
   TITLE:

   What it Does:

   Who Made it: YOUR NAME, DATE
*/
const int SPEAKER = 3;
//============================================================
const int sensorUpdateMillis = 200;
unsigned long lastReadMillis = 0;
unsigned long toneLengthMillis = 100;
unsigned long toneRepeatMillis = 200;
unsigned long toneLastRepeatMillis = 0;
//============================================================
const uint8_t threshCount = 7;
int bassTab[threshCount] = {1911, 1702, 1516, 1431, 1275, 1136, 1012}; //bass 1~7
int distanceThresh[threshCount] = {50, 100, 150, 200, 250, 300, 350};
uint8_t noteIndex = 0;
//============================================================
// defines pins numbers
const int trigPin = 10;
const int echoPin = 11;
//============================================================
int distance1 = 0;
int distance2 = 0;
int distanceDifference = 0;
//============================================================
void setup()
{
  pinInit();
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}

//============================================================

void loop()
{
  if ((millis() - lastReadMillis) < sensorUpdateMillis)
  {
    distance1 = proximityRead(trigPin, echoPin);
//    distance2 = proximityRead(trigPin, echoPin);
//    distanceDifference = distance2 - distance1;
  }
  someSeriesOfDecisions();
  sound(noteIndex);
}
