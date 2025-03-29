int button=13;
int redPin=7;
void setup() {
  pinMode(button,INPUT);
  pinMode(redPin,OUTPUT);
}

void loop() {
  if(digitalRead(button)==HIGH){
    digitalWrite(redPin,HIGH);
  }else{
    digitalWrite(redPin,LOW);
  }
}
