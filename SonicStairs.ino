double sensor;
double state;

void setup() {
  state = 0;
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
    if(sensor < 100){
      if (state == 0) {
        state = 1;
        tone(8, 523.23);
        delay(1000);
      } else {
        noTone(8);
      }
    } else {
      state = 0;
      noTone(8);
    }
  }
}
