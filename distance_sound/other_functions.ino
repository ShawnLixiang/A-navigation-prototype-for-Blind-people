
void someSeriesOfDecisions()
{
  if (abs(distanceDifference) < 100)
  {
    Serial.println(distance1);
    if (0 <= distance1 && distance1 < 50)
    {
      Serial.println("hi1");
      for (int note_index = 0; note_index < 7; note_index++)
      {
        sound(6);
      }
    }
    if (50 <= distance1 && distance1 < 100)
    {
      Serial.println("hi2");
      for (int note_index = 0; note_index < 7; note_index++)
      {
        sound(5);
      }
    }
    if (100 <= distance1 && distance1 < 150)
    {
      Serial.println("hi3");
      for (int note_index = 0; note_index < 7; note_index++)
      {
        sound(4);
      }
    }
    if (150 <= distance1 && distance1 < 200)
    {
      Serial.println("hi4");
      for (int note_index = 0; note_index < 7; note_index++)
      {
        sound(3);
      }
    }
    if (200 <= distance1 && distance1 < 250)
    {
      Serial.println("hi5");
      for (int note_index = 0; note_index < 7; note_index++)
      {
        sound(2);
      }
    }
    if (250 <= distance1 && distance1 < 300)
    {
      Serial.println("hi6");
      for (int note_index = 0; note_index < 7; note_index++)
      {
        sound(1);
      }
    }
    if (300 <= distance1 && distance1 < 350)
    {
      Serial.println("hi7");
      for (int note_index = 0; note_index < 7; note_index++) {
        sound(1);
      }
    }
    Serial.println("hi");
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
