#define buttonOne A0
#define buttonTwo A1
#define buttonOneLED 12
#define buttonTwoLED 8

String previousMessage = "";

void setup()
{
  Serial.begin(9600);
  pinMode(buttonTwoLED, OUTPUT);
  pinMode(buttonOneLED, OUTPUT);
  pinMode(buttonOne,    OUTPUT);
  pinMode(buttonTwo,    OUTPUT);
}

void loop()
{
  if (digitalRead(buttonOne))
  {
    Serial.println("buttonOneIsHIGH");
    delay(100);
  }

  if (digitalRead(buttonTwo))
  {
    Serial.println("buttonTwoIsHIGH");
    delay(100);
  }

  String st1 = Serial.readString();
  st1.trim();
  if (!(st1.equals(previousMessage)))
  {
    if (st1.equals("buttonOneIsHIGH"))
    {
      digitalWrite(buttonOneLED, HIGH);
      digitalWrite(buttonTwoLED, LOW);
    }
    if (st1.equals("buttonTwoIsHIGH"))
    {
      digitalWrite(buttonTwoLED, HIGH);
      digitalWrite(buttonOneLED, LOW);
    }
    st1 = previousMessage;
  }


}
