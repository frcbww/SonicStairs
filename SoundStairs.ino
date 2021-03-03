double sensor;

void setup() {
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
    if(sensor < 150){
      tone(8, 1567.96);
    } else {
      noTone(8);
    }
  }
}
