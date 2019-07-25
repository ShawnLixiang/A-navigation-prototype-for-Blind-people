/*
   TITLE:

   What it Does:

   Who Made it: YOUR NAME, DATE
*/
const int SPEAKER = 3;
//============================================================
const int sensorUpdateMillis = 100;
unsigned long lastReadMillis = 0;
unsigned long toneLengthMillis = 50;
unsigned long toneRepeatMillis = 400;
//============================================================
int bassTab[] = {1911, 1702, 1516, 1431, 1275, 1136, 1012}; //bass 1~7
int distanceThresh[] = {50, 100, 150, 200, 250, 300, 350};
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
  distance1 = proximityRead(trigPin, echoPin);
  distance2 = proximityRead(trigPin, echoPin);
  distanceDifference = distance2 - distance1;
  someSeriesOfDecisions();
}
