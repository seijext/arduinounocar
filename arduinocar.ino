#define PWMB 9
#define BIN2 8
#define BIN1 7
#define STBY 6
#define AIN1 5
#define AIN2 4
#define PWMA 3

int Speed = 100;
char Move = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("ON UART");
  pinMode(10, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  digitalWrite(STBY, 1);
}

void loop() {
  if (Serial.available() > 0) {
    Move = Serial.read();
    Motor(0, 0);
    analogWrite(10, 0);
    Speed = 255;
    switch (Move) {
      case 'F':
        Motor(Speed, Speed);
        break;
      case 'B':
        Motor(-Speed, -Speed);
        break;
      default:
        break;
    }
  }
}

void Motor(int left, int right) {
  analogWrite(PWMA, abs(right));
  analogWrite(PWMB, abs(left));

  if (right > 0) {
    digitalWrite(AIN1, 0); digitalWrite(AIN2, 1);
  }
  else {
    digitalWrite(AIN1, 1); digitalWrite(AIN2, 0);
  }

  if (left < 0) {
    digitalWrite(BIN1, 0); digitalWrite(BIN2, 1);
  }
  else {
    digitalWrite(BIN1, 1); digitalWrite(BIN2, 0);
  }

  delay(2000);

  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 1);
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 1);


}
