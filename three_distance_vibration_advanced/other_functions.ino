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
  if (abs(difference) < 100)
  {
    Serial.print("sensor1:");
    Serial.println(distance);
    if (0 <= distance && distance < 50)
    {
      analogWrite(motorPin, 255);
      delay(500);
    }
    else if (50 <= distance && distance < 100)
    {
      analogWrite(motorPin, 219);
      delay(500);
    }
    else if (100 <= distance && distance < 150)
    {
      analogWrite(motorPin, 183);
      delay(500);
    }
    else if (150 <= distance && distance < 200)
    {
      analogWrite(motorPin, 147);
      delay(500);
    }
    else if (200 <= distance && distance < 250)
    {
      analogWrite(motorPin, 111);
      delay(500);
    }
    else if (250 <= distance && distance < 300)
    {
      analogWrite(motorPin, 75);
      delay(500);
    }
    else if (300 <= distance && distance < 350)
    {
      analogWrite(motorPin, 39);
      delay(500);
    }
    else
    {
      analogWrite(motorPin, 0);
    }
  }
}
