
void someSeriesOfDecisions()
{
  if (abs(distanceDifference) < 100)
  {
    Serial.println(distance1);
    if (distance1 < 50)
    {
      sound(6);
    }
    else if (distance1 < 100)
    {
      sound(5);
    }
    else if (distance1 < 150)
    {
      sound(4);
    }
    else if (distance1 < 200)
    {
      sound(3);
    }
    else if ( distance1 < 250)
    {
      sound(2);
    }
    else if (distance1 < 300)
    {   
        sound(1);      
    }
    else
    {
        sound(0);     
    }
  }
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
  while ((millis() - lastReadMillis) < sensorUpdateMillis)
  {

    digitalWrite(SPEAKER, HIGH);
    delayMicroseconds(bassTab[note_index]);
    digitalWrite(SPEAKER, LOW);
    delayMicroseconds(bassTab[note_index]);

  }
}
