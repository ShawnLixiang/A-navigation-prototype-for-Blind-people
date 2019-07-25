const int motorPin = 9;
const int intensity[] = {0, 60, 90, 160, 200, 255};
void setup()
{
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);
  Serial.begin(9600);

  //  for ( int i = 60; i < 255 ; i += 30)
  //  {
  //    analogWrite(motorPin, i);
  //    Serial.println(i);
  //    delay(1000);
  //  }

  for ( int i = 0; i < 6; i++)
  {
    analogWrite(motorPin, intensity[i]);
    Serial.println(intensity[i]);
    delay(1000);
  }

}

void loop()
{


}
