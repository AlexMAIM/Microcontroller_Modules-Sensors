/*#1 mini-project
Credits: AlexMAIM
*/

#define potentiometer A0
const int button =2;
const int ledYellow = 3;
const int ledBlue = 5;
int buttonState,potentiometerValue,brightnessLedYellow;
void setup()
{
  pinMode(ledBlue,OUTPUT);
  pinMode(ledYellow,OUTPUT);
  pinMode(button,INPUT_PULLUP);
}
void loop()
{
  buttonState=digitalRead(button);
  potentiometerValue=analogRead(potentiometer);
  brightnessLedYellow=map(potentiometerValue,0,1023,0,255);
  if(!buttonState)
  {
   digitalWrite(ledBlue,HIGH);
  }
  else
  {
    digitalWrite(ledBlue,LOW);
  }
  analogWrite(ledYellow,brightnessLedYellow);
  delay(350);
}