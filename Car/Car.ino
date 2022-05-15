#define EchoPin A4 
#define TrigPin A5

void setup()
{
  pinMode(rightIRSensor,INPUT);
  pinMode(leftIRSensor,INPUT);
  pinMode(EchoPin,INPUT);
  pinMode(TrigPin,OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:

}
