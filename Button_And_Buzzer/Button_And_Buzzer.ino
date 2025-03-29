int button1=13, button2=12, buzzer=2;
int on=450;
void setup() {
  Serial.begin(9600);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  if(digitalRead(button1)==HIGH){
  	Serial.println("You are pressing button1. ");
    digitalWrite(buzzer,HIGH);
    delay(on);
  }
  else if(digitalRead(button2)==HIGH){
  	Serial.println("You are pressing button2. ");
    digitalWrite(buzzer,HIGH);
    delay(on);
  }
  else{
          	digitalWrite(buzzer,LOW);
          }
}
