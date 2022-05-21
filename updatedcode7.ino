//Car run straight test

// Pin assign to each tire
const int left_f_tire = 2; 
const int right_f_tire = 3;
const int left_b_tire = 4;
const int right_b_tire = 5;

void setup() {
  // default setting for each tire 
  pinMode(left_f_tire, OUTPUT);
  pinMode(left_b_tire, OUTPUT);
  pinMode(right_f_tire, OUTPUT);
  pinMode(right_b_tire, OUTPUT);
}

void loop() {
  // this command goes as car move straight for 2 seconds 
  digitalWrite(left_f_tire, HIGH);
  digitalWrite(right_f_tire, HIGH);
  digitalWrite(left_b_tire, LOW);
  digitalWrite(right_b_tire, LOW);
  delay(2000);

  // this command goes as car move reverse for 2 seconds
  digitalWrite(left_f_tire, LOW);
  digitalWrite(right_f_tire, LOW);
  digitalWrite(left_b_tire, HIGH);
  digitalWrite(right_b_tire, HIGH);
  delay(2000);\
}
