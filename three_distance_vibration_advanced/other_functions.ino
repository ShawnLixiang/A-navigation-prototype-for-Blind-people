int proximityRead(int proximityTrigPin, int proximityEchoPin)
{
  long duration;
  int distance;
  digitalWrite(proximityTrigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(proximityTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(proximityTrigPin, LOW);

  duration = pulseIn(proximityEchoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds

  distance = duration / (2 * 29); // Calculating the distance 1/29 ~= 0.034

  return distance;
}

//============================================================
void checkReading(int motorPin, int distance, int difference)
{
  if (abs(distanceDifference) < 100)
  {
    for (int i = 0; i < threshCount; ++i)
    {
      if (distance1 < distanceThresh[i])
      {
        analogWrite(motorPin, intensityMap[threshCount - 1 - i]);
        break;
      }
    }
  }
}
