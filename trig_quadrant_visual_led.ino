int sinPin = 0;
int cosPin = 1;
int tanPin = 2;

int quadrant1 = 3;
int quadrant2 = 4;
int quadrant3 = 5;
int quadrant4 = 6;

int switch1 = 7;
int switch2 = 8;
int switch3 = 9;
int switch4 = 10;
int switch5 = 11;
int switch6 = 12;

void setup() {
  pinMode(sinPin, OUTPUT);
  pinMode(cosPin, OUTPUT);
  pinMode(tanPin, OUTPUT);

  pinMode(quadrant1, OUTPUT);
  pinMode(quadrant2, OUTPUT);
  pinMode(quadrant3, OUTPUT);
  pinMode(quadrant4, OUTPUT);

  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
  pinMode(switch5, INPUT_PULLUP);
  pinMode(switch6, INPUT_PULLUP);

  digitalWrite(sinPin, LOW);
  digitalWrite(cosPin, LOW);
  digitalWrite(tanPin, LOW);
  digitalWrite(quadrant1, LOW);
  digitalWrite(quadrant2, LOW);
  digitalWrite(quadrant3, LOW);
  digitalWrite(quadrant4, LOW);
}


int switchValues[6] = {10, 20, 40, 80, 160, 320}; 

int readAngle() {
  int angle = 0;
  for(int i=0; i<6; i++){
    if(digitalRead(switch1 + i) == LOW) { 
      angle += switchValues[i];
    }
  }
  angle = angle % 360; 
  return angle;
}

void setQuadrants(int angle) {
  digitalWrite(quadrant1, angle >= 0 && angle < 90 ? HIGH : LOW);
  digitalWrite(quadrant2, angle >= 90 && angle < 180 ? HIGH : LOW);
  digitalWrite(quadrant3, angle >= 180 && angle < 270 ? HIGH : LOW);
  digitalWrite(quadrant4, angle >= 270 && angle < 360 ? HIGH : LOW);
}

void setTrigSigns(int angle) {
  digitalWrite(sinPin, (angle >= 0 && angle < 180) ? HIGH : LOW);
  digitalWrite(cosPin, (angle < 90 || (angle >= 270 && angle < 360)) ? HIGH : LOW);
  digitalWrite(tanPin, ((angle >=0 && angle < 90) || (angle >=180 && angle <270)) ? HIGH : LOW);
}

void loop() {
  int angle = readAngle();     
  setQuadrants(angle);          
  setTrigSigns(angle);        
}
