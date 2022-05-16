const int motor_1_f = 19;
const int motor_1_b = 18;
const int motor_2_f = 17;
const int motor_2_b = 5;


void setup() {
  pinMode(motor_1_f, OUTPUT);
  pinMode(motor_1_b, OUTPUT);
  pinMode(motor_2_f, OUTPUT);
  pinMode(motor_2_b, OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(motor_1_b, LOW);
  digitalWrite(motor_2_b, LOW);
  digitalWrite(motor_1_f, HIGH);
  digitalWrite(motor_2_f, HIGH);
