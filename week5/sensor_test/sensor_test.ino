const int analogOutPin=11;
const int analogOutPin2=10;
const int analogInPin=0;
int sensorValue = 0;
int outputValue = 0;
int sensorLow = 10;
int sensorHigh = 500;
void setup()
{
  pinMode(analogOutPin,OUTPUT);
  pinMode(analogOutPin2,OUTPUT);
  pinMode(analogInPin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  sensorValue=analogRead(analogInPin);
  outputValue = map(sensorValue, sensorLow, sensorHigh, 0, 255);
  analogWrite(analogOutPin,outputValue);
  analogWrite(analogOutPin2,outputValue);
  Serial.println(sensorValue);
 }
