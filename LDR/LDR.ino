int greenPin=11;
int buzzer=7;
int LDR=A0;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(greenPin,OUTPUT);
}

void loop() {
  int light=analogRead(LDR);
  Serial.print("light : ");
  Serial.println(light);
  if(light<=5){
    digitalWrite(greenPin,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(450);
  }else{
    digitalWrite(greenPin,LOW);
    digitalWrite(buzzer,LOW);
    delay(450);
  }
}
