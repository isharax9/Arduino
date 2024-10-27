#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(3, 4); // trig , echo

#include <Servo.h>
Servo s = Servo();

int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int ENB = 5;
int IN3 = 7;
int IN4 = 6;

void setup() {
  // put your setup code here, to run once:
  s.attach(2);  // Servo

  // Motor A
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  analogWrite(ENA, 250);

  // Motor B
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  analogWrite(ENB, 250);

  Serial.begin(9600); // Serial
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = Serial.read();

  // Forward
  if (x == '1') {
    s.write(120);
    delay(300);
    s.write(111);  
    int d = u.read();
    delay(400);
    if (d > 20) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN4, HIGH);
      digitalWrite(IN3, LOW);
      delay(250);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN4, LOW);
      digitalWrite(IN3, LOW);
    }
    delay(300);
    s.write(115);
  }

  // Reverse
    if (x == '2') {
    s.write(0);
    delay(300);
    s.write(180);  
    int d = u.read();
    delay(400);
    if (d > 20){

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    delay(150);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, LOW);
  }
 }
  // Stop
  if (x == '3') {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, LOW);
  }

  // Turn Right
  if (x == '4') {
    s.write(60);
    delay(300);
    int d = u.read();
    if (d > 10) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN4, LOW);
      digitalWrite(IN3, HIGH);
      delay(200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN4, LOW);
      digitalWrite(IN3, LOW);
    }
     delay(300);
    s.write(115);
  }

  // Turn Left
  if (x == '5') {
    s.write(175);
    delay(300);
    int d = u.read();
    if (d > 10) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN4, HIGH);
      digitalWrite(IN3, LOW);
      delay(200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN4, LOW);
      digitalWrite(IN3, LOW);
    }
    delay(300);
    s.write(115);
  }
}
