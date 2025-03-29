int button=13;
int on=450,off=900;
int redPin=7;
void setup() {
  pinMode(button,INPUT);
  pinMode(redPin,OUTPUT);
}

void loop() {
  if(digitalRead(button)==HIGH){
    digitalWrite(redPin,HIGH);
    delay(on);
  }else{
    digitalWrite(redPin,LOW);
    delay(off);
  }
}
