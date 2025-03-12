
int pinBlue=2;
int pinRed=3;
int offtime=1000;
int ontime=2000;

void setup() {
  pinMode(pinBlue,OUTPUT);
  pinMode(pinRed,OUTPUT);

}

void loop() {
  digitalWrite(pinBlue,HIGH);
  digitalWrite(pinRed,LOW);
  delay(ontime);
  digitalWrite(pinBlue,LOW);
  digitalWrite(pinRed,HIGH);
  delay(offtime);

}
