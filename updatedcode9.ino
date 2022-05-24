// in this code we have completed code of IR sensor, ultrasonic sensor, motor driver and wiring of the car .

#define trigPin 10
#define echoPin 11

#define left_infr 32
#define right_infr 12

#define left_f_tyre 24
#define left_b_tyre 23
#define right_f_tyre 23
#define right_b_tyre 31

long time;
int displacement;

int calc_displacement();

void setup() {
  Serial.begin(9600);
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
  Serial.println(displacement);
  Serial.println("Left: ");
  Serial.println(digitalRead(left_infr));
  Serial.println("Right: ");
  Serial.println(digitalRead(right_infr));
  if(displacement <= 10){ //go straight - follow hand
    digitalWrite(left_f_tyre, HIGH);
    digitalWrite(right_f_tyre, HIGH);
    digitalWrite(left_b_tyre, LOW);
    digitalWrite(right_b_tyre, LOW);
    delay(200);
    Serial.println("Straight");
  }

  
  else if(digitalRead(left_infr) == HIGH && digitalRead(right_infr) == LOW){ //Turn Left
    digitalWrite(left_f_tyre, LOW);
    digitalWrite(right_f_tyre, HIGH);
    digitalWrite(left_b_tyre, HIGH);
    digitalWrite(right_b_tyre, LOW);
    delay(200);
    Serial.println("Left");
  }
  else if(digitalRead(right_infr) == HIGH && digitalRead(left_infr) == LOW){  //Turn Right
    digitalWrite(left_f_tyre, HIGH);
    digitalWrite(right_f_tyre, LOW);
    digitalWrite(left_b_tyre, LOW);
    digitalWrite(right_b_tyre, HIGH);
    delay(200);
    Serial.println("Right");
  }

  reset();
}

int calc_displacement(){
  long x;
  long y;
  digitalWrite(trigPin, LOW); //clear trigger pin from previous loop
  delayMicroseconds(2); //using Microseconds as the delay needs to be very very short - delay uses millisecond
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  //trigger pin high for 10 microsecond - sound wave sent
  digitalWrite(trigPin, LOW); //reset trigger pin

  time = pulseIn(echoPin, HIGH);  //reading and storing time it takes for echo
  //time contains sound travel time in microseconds
 
  displacement = time * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  //displacement contains displacement in centimeter
  Serial.println(displacement);
  return displacement;
}

void reset(){
  digitalWrite(left_f_tyre, LOW);
  digitalWrite(right_f_tyre, LOW);
  digitalWrite(left_b_tyre, LOW);
  digitalWrite(right_b_tyre, LOW);
}
