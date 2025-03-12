
int pin=3;
int offtime=900;
int ontime=100;

void setup() {
  pinMode(pin,OUTPUT);

}

void loop() {
  digitalWrite(pin,HIGH);
  delay(ontime);
  digitalWrite(pin,LOW);
  delay(offtime);

}
