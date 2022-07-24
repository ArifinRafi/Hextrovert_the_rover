int R_IS = 1;
int L_IS = 2;
int R_EN = 3;
int L_EN = 4;
int RPWM_1 = 5;
int LPWM_1 = 6;
int RPWM_2 = 9;
int LPWM_2 = 10;
char = state;
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
  

  digitalWrite(R_IS, LOW);
  digitalWrite(L_IS, LOW);
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
  Serial.begin(9600);
}

void loop(){
 if (Serial.available>0) {
  state = Serial.read();

  if (state == 'w') {
    forward();
  }
  
 }
  
}


forward() {
  analogWrite(RPWM_1, speed);
  analogWrite(RPWM_2, speed);
}


        
