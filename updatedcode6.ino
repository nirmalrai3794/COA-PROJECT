const int echoPin = 4
const int trigPin = 5
const int IR = 6;
const int led_sonic = 7;
const int led_infr = 8;

long time1;
int displacement;

void setup() {
  pinMode(led_sonic, OUTPUT);
  pinMode(led_infr, OUTPUT)
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(IR, INPUT);  
}
void loop() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW); 

  time1 = pulseIn(echoPin, HIGH);  

  displacement = time1 * 0.034 / 2; 
  Serial.print("displacement: ");
  Serial.print(displacement);
  Serial.println(" cm");

 if(displacement <= 20){
    digitalWrite(led_sonic, HIGH);
  }
  else{
    digitalWrite(led_sonic, LOW);
  }
  Serial.println("Infrared: ");
  
  if(digitalRead(IR)==HIGH){
    Serial.println("Detected");
    digitalWrite(led_infr, HIGH);
  }
  else{
     Serial.println("Not detected");
      digitalWrite(led_infr, LOW);
  }
}
