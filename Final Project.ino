#define trig 13 // trig in ultrasonic sensor is used to trigger the pulse 
#define echo 12 //  echo in ultrasonic sensor is used to recieve the pulse and record it 

#define l_ir 33 // Left IR sensor is used to move Car in left Direction 
#define r_ir 32 // Right IR sensor is used to move Car in Right Direction 

#define in1 14 // Tire 1
#define in2 26 // Tire 2
#define in3 25 // Tire 3
#define in4 27 // Tire 4

long time1; // time used in ultrasonic sensor 
int displacement; // Distance between ultrasonic Sensor and a object infront of it

int left_val; // Value produced by left IR sensor
int right_val; // Value produced by Right IR sensor

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(l_ir, INPUT);
  pinMode(r_ir, INPUT);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  displacement = calc_displacement();
  left_val = digitalRead(l_ir);
  right_val = digitalRead(r_ir);
  
  if (displacement < 10){
    stop();
  }
  
  else if(displacement <= 30 && displacement >= 10 && left_val == 1 && right_val == 1){
    straight();
  }
    
  else if(left_val == 0 && right_val == 1){
    right();
  }
  
  else if(right_val == 0 && left_val == 1){
    left();
  }
  off(); 
}

int calc_displacement(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time1= pulseIn(echo, HIGH);
 
  displacement = time1* 0.034 / 2;
  
  Serial.println("displacement: ");
  Serial.println(displacement);
  
  return displacement;
}

// Straight Function Used to move car in Straight Direction
void straight(){
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
  Serial.println("Straight");
  delay(50);
}
// Moves Left in Direction 
void left(){        
  digitalWrite(in1, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("Left");
  delay(50);
}
// Moves Left in Direction 
void right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("Right");
  delay(50);
}
// Car Is being Stopped Because 
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  Serial.println("Stop");
}
// Car Is being Stopped if none of sensor is been bepped 
void off(){
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);  
}
