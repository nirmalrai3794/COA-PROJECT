const int EchoPin = 2
const int TrigPin = 3
const int Led = 4;

long Time;
int displacement;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT); //trigger pin sends output signal
  pinMode(echoPin, INPUT); //echo pin receives input signal
}
void loop() {
  digitalWrite(TrigPin, LOW); //clearing the trigger pin 
  delayMicroseconds(5); // delay of only 5 seconds necessary 
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);  //making the trigger pin for 10 microseconds 
  digitalWrite(TrigPin, LOW); //this goes in the loop.
 
