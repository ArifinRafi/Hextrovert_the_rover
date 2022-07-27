int R_IS = 14;
int L_IS = 15;
int R_EN = 16;
int L_EN = 17;

//motor1
int RPWM_1 = 2;
int LPWM_1 = 3;

//motor2
int RPWM_2 = 4;
int LPWM_2 = 5;

//motor3
int RPWM_3 = 6;
int LPWM_3 = 7;

//motor4
int RPWM_4 = 8;
int LPWM_4 = 9;

//motor5
int RPWM_5 = 10;
int LPWM_5 = 11;

//motor6
int RPWM_6 = 12;
int LPWM_6 = 13;

int speed1 = 150;
int speed2 = 100;



void setup() {
  //define pinmode

  pinMode(R_IS, OUTPUT);
  pinMode(L_IS, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  
  //Motor 1
  pinMode(RPWM_1 , OUTPUT);
  pinMode(LPWM_1, OUTPUT);

  //Motor 2
  pinMode(RPWM_2 , OUTPUT);
  pinMode(LPWM_2, OUTPUT);

  //Motor 3
  pinMode(RPWM_3 , OUTPUT);
  pinMode(LPWM_3, OUTPUT);

  //Motor 4
  pinMode(RPWM_4 , OUTPUT);
  pinMode(LPWM_4, OUTPUT);

  //Motor 5
  pinMode(RPWM_5 , OUTPUT);
  pinMode(LPWM_5, OUTPUT);

  //Motor 6
  pinMode(RPWM_6 , OUTPUT);
  pinMode(LPWM_6, OUTPUT);
  

  digitalWrite(R_IS, LOW);
  digitalWrite(L_IS, LOW);
  
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()>0) {
  char state = Serial.read();

  if (state == 'w') {
    forward();
  }
  else if (state == 'x') {
   reset();
  }
  else if (state == 's') {
   backward();
  }
  else if (state == 'd') {
   right();
  }
  else if (state == 'a') {
   left();
  }
  
 }
  
}
  


void forward() {
  analogWrite(RPWM_1, speed1);
  analogWrite(RPWM_2, speed1);
  analogWrite(RPWM_3, speed1);
  analogWrite(RPWM_4, speed1);
  analogWrite(RPWM_5, speed1);
  analogWrite(RPWM_6, speed1);
}

void backward() {
  analogWrite(LPWM_1, speed1);
  analogWrite(LPWM_2, speed1);
  analogWrite(LPWM_3, speed1);
  analogWrite(LPWM_4, speed1);
  analogWrite(LPWM_5, speed1);
  analogWrite(LPWM_6, speed1);
}


void right() {
  analogWrite(RPWM_1, speed2);
  analogWrite(RPWM_3, speed2);
  analogWrite(RPWM_5, speed2);
  
  analogWrite(LPWM_2, speed2);
  analogWrite(LPWM_4, speed2);
  analogWrite(LPWM_6, speed2);
}

void left() {
  
  analogWrite(RPWM_2, speed2);
  analogWrite(RPWM_4, speed2);
  analogWrite(RPWM_6, speed2);

  analogWrite(LPWM_1, speed2);
  analogWrite(LPWM_3, speed2);
  analogWrite(LPWM_5, speed2);
}

void reset() {
  analogWrite(RPWM_1, 0);
  analogWrite(RPWM_2, 0);
  
}
