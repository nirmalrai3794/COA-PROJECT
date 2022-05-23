// In this code we have merged two codes in one (Car +Ultrasonic)

const int trigPin = 9;
const int echoPin = 10;
const int left_f_tyre = 3;
const int right_f_tyre = 4;
const int left_b_tyre = 5;
const int right_b_tyre = 6;

long time1;
int displacement;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(left_f_tyre, OUTPUT);
  pinMode(left_b_tyre, OUTPUT);
  pinMode(right_f_tyre, OUTPUT);
  pinMode(right_b_tyre, OUTPUT);
}

void loop() {

  displacement = calc_displacement();
  if (displacement <= 15 && displacement >= 5) { //go straight - follow hand
    digitalWrite(left_f_tyre, HIGH);
    digitalWrite(right_f_tyre, HIGH);
    digitalWrite(left_b_tyre, LOW);
    digitalWrite(right_b_tyre, LOW);
    delay(250); //follows for 0.25 seconds and then reads signal again (loop runs again)
  }
  else if (displacement < 5) {
    digitalWrite(left_f_tyre, LOW);
    digitalWrite(right_f_tyre, HIGH);
    digitalWrite(left_b_tyre, HIGH);
    digitalWrite(right_b_tyre, LOW);
    delay(100); //reverse to stop momentem
  }
}

int calc_displacement() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW); 

  time1 = pulseIn(echoPin, HIGH);  //reading and storing time it takes for echo
  //time contains sound travel time in microseconds

  displacement = time1 * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  //displacement contains displacement in centime1ter

  return displacement;
}
