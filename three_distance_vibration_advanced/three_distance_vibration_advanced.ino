/*
   TITLE:

   What it Does:

   Who Made it: YOUR NAME, DATE
*/
const int motorPin[] = {9, 10, 11};
const int trigPin[]  = {2, 4, 6};
const int echoPin[]  = {3, 5, 7};
//============================================================
const uint8_t threshCount = 7;
int intensityMap[threshCount] = {0, 30, 60, 90, 130, 190, 255};
int distanceThresh[threshCount] = {50, 100, 150, 200, 250, 300, 350};
//============================================================
int distance1 = 0;
int distance2 = 0;
int distanceDifference = 0;
//============================================================
void setup()
{
  for (int i = 0; i < 3; ++i)
  {
    pinMode(trigPin[i], OUTPUT);
    pinMode(echoPin[i], INPUT);
    pinMode(motorPin[i], OUTPUT);
    digitalWrite(motorPin[i], LOW);
  }
  Serial.begin(9600);
}

//============================================================

void loop()
{
  for (int i = 0; i < 3; ++i)
  {
    distance1 = proximityRead(trigPin[i], echoPin[i]);
    distance2 = proximityRead(trigPin[i], echoPin[i]);
    distanceDifference = distance2 - distance1;
    checkReading(motorPin[i], distance1, distanceDifference);
  } 
}

void filterReading(int j)
{
  for (int i = 0; i < 10; ++i)
  {
    distance1 = proximityRead(trigPin[j], echoPin[j]);
    distance2 = proximityRead(trigPin[j], echoPin[j]);
  } 
}
