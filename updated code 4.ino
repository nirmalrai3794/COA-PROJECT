const int Infra_red_Sensor = 4;

void setup() {
  pinMode(Infra_red_Sensor,INPUT);
}

void loop() {
  if(digitalRead(Infra_red_Sensor)==HIGH){
    Serial.println("Contact Detected");
  }
  else{
    Serial.println("Contact Not Detected");
  }
}
