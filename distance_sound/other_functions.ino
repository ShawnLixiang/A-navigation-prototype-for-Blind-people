
void someSeriesOfDecisions()
{
  //  if (abs(distanceDifference) < 100)
  //  {
  for (int i = 0; i < threshCount; ++i)
  {
    if (distance1 < distanceThresh[i])
    {
      noteIndex = (threshCount - 1) - i;
      break;
    }
  }
  //  }
}

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
  lastReadMillis = millis();
  return distance;
}

void pinInit()
{
  pinMode(SPEAKER, OUTPUT);
  digitalWrite(SPEAKER, LOW);
}

void sound(uint8_t note_index)
{

  if ((millis() - toneLastRepeatMillis) > toneRepeatMillis)
  {
    toneLastRepeatMillis = millis();
    while ((millis() - toneLastRepeatMillis) < toneLengthMillis)
    {
      digitalWrite(SPEAKER, HIGH);
      delayMicroseconds(bassTab[note_index]);
      digitalWrite(SPEAKER, LOW);
      delayMicroseconds(bassTab[note_index]);
    }
  }
}
