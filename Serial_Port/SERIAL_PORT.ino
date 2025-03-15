int bluePinMode=9;
int redPinMode=3;
int blueOnTime=1000;
int blueOffTime=1500;
int redOnTime=900;
int redOffTime=100;

void setup() {
  Serial.begin(19200);
  pinMode(bluePinMode,OUTPUT);
  pinMode(redPinMode,OUTPUT);
  
}

void loop() {
  
  for (int i=0;i<6;i++){
    
    if(i>=3){
      Serial.print(" You are in RED blink : ");
      Serial.println(i);
      digitalWrite(redPinMode,HIGH);
      delay(redOnTime);
      digitalWrite(redPinMode,LOW);
      delay(redOffTime);
    }
    else{
      Serial.print(" You are in BLUE blink : ");
      Serial.println(i);
      digitalWrite(bluePinMode,HIGH);
      delay(blueOnTime);
      digitalWrite(bluePinMode,LOW);
      delay(blueOffTime);
    }
  }
}
