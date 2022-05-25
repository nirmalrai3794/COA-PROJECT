//Final Code

#define trigPin 12
#define echoPin 13

#define left_infr 14
#define right_infr 32

#define left_f_tyre 27
#define left_b_tyre 26
#define right_f_tyre 25
#define right_b_tyre 33

long time1;
int displacement;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(left_infr, INPUT);
  pinMode(right_infr, INPUT);
  
  pinMode(left_f_tyre, OUTPUT);
  pinMode(left_b_tyre, OUTPUT);
  pinMode(right_f_tyre, OUTPUT);
  pinMode(right_b_tyre, OUTPUT);
}

void loop() {

  displacement = calc_displacement();
  
  if(displacement <= 15 && displacement >= 5){  //go straight - follow hand
    digitalWrite(left_f_tyre, HIGH);
    digitalWrite(right_f_tyre, HIGH);
    digitalWrite(left_b_tyre, LOW);
    digitalWrite(right_b_tyre, LOW);
    delay(250); //follows for 0.25 seconds and then reads signal again (loop runs again)
    Serial.println("Straight");
  }
  else if(displacement < 5){
    digitalWrite(left_f_tyre, LOW);
    digitalWrite(right_f_tyre, HIGH);
    digitalWrite(left_b_tyre, HIGH);
    digitalWrite(right_b_tyre, LOW);
    delay(100); //reverse to stop momentem
    Serial.println("Stop");
  }
  
  else if(digitalRead(left_infr) == HIGH && digitalRead(right_infr) == LOW){ //Turn Left
    digitalWrite(left_f_tyre, LOW);
    digitalWrite(right_f_tyre, HIGH);
    digitalWrite(left_b_tyre, HIGH);
    digitalWrite(right_b_tyre, LOW);
    delay(250);
    Serial.println("Left");
  }
  else if(digitalRead(right_infr)==HIGH && digitalRead(left_infr) == LOW){  //Turn Right
    digitalWrite(left_f_tyre, HIGH);
    digitalWrite(right_f_tyre, LOW);
    digitalWrite(left_b_tyre, LOW);
    digitalWrite(right_b_tyre, HIGH);
    delay(250);
    Serial.println("Right");
  }
}

int calc_displacement(){
  digitalWrite(trigPin, LOW); //clear trigger pin from previous loop
  delayMicroseconds(2); //using Microseconds as the delay needs to be very very short - delay uses millisecond
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  //trigger pin high for 10 microsecond - sound wave sent
  digitalWrite(trigPin, LOW); //reset trigger pin

  time1 = pulseIn(echoPin, HIGH);  //reading and storing time1 it takes for echo
  //time1 contains sound travel time1 in microseconds
 
  displacement = time1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  //displacement contains displacement in centime1ter

  return displacement;
}
