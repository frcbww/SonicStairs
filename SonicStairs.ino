double sensor;
bool isInit;
double lastTime;

void setup() {
  isInit = false;
  lastTime = 0;
}

void loop () {
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  pinMode(9, INPUT);
  sensor = pulseIn(9, HIGH);
  
  if(sensor > 0) {
    sensor = sensor / 2;
    sensor = sensor * 340 * 100 / 1000000;
    if(sensor < 80){
      isInit = false;
      tone(8, 261.63);
    } else {
      if (!isInit) {
        isInit = true;
        lastTime = millis();
      } else {
        if (millis() - lastTime > 500) {
          noTone(8);
        } else {
          tone(8, 261.63);
        }
      }
    }
//    if(sensor < 80){
//      tone(8, 261.63, 300);
//    }
  }
}
