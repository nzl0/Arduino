int pinRedMode=3;
int pinBlueMode=9;
int blueOnTime=900;
int blueOffTime=100;
int redOnTime=100;
int redOffTime=900;


void setup() {
  pinMode(pinRedMode,OUTPUT);
  pinMode(pinBlueMode,OUTPUT);
 
}

void loop() {
  
  for(int i=0;i<5;i++){
    digitalWrite(pinBlueMode,HIGH);
    delay(blueOnTime);
    digitalWrite(pinBlueMode,LOW);
    delay(blueOffTime);
  }

  for(int j=0;j<4;j++){
    digitalWrite(pinRedMode,HIGH);
    delay(redOnTime);
    digitalWrite(pinRedMode,LOW);
    delay(redOffTime);
  }

}
