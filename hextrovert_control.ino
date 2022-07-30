int R_IS = 22;
int L_IS = 23;
int R_EN = 24;
int L_EN = 25;

//motor1, motor3
int RPWM_1 = 2;
int LPWM_1 = 3;

//motor2, motor4
int RPWM_2 = 4;
int LPWM_2 = 5;

//motor 5, motor 6
int RPWM_3 = 6;
int LPWM_3 = 7;

int speed1 = 150;
int speed2 = 100;



void setup() {
  //define pinmode

  pinMode(R_IS, OUTPUT);
  pinMode(L_IS, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  
  //motor1, motor3 and motor5
  pinMode(RPWM_1 , OUTPUT);
  pinMode(LPWM_1, OUTPUT);

  //motor2, motor4 and motor6
  pinMode(RPWM_2 , OUTPUT);
  pinMode(LPWM_2, OUTPUT);
  

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
}

void backward() {
  analogWrite(LPWM_1, speed1);
  analogWrite(LPWM_2, speed1);
}


void right() {
  analogWrite(RPWM_1, speed2);
  analogWrite(LPWM_2, speed2);
  
}

void left() {
  
  analogWrite(RPWM_2, speed2);
  analogWrite(LPWM_1, speed2);
}

void reset() {
  analogWrite(RPWM_1, 0);
  analogWrite(RPWM_2, 0);
  
}
