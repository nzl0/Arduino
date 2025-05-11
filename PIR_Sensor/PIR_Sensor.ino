int led=4;//dijital output
int LDR=A0; //analog input
int PIR=2; //dijital output
unsigned long ctr=0;
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(LDR,INPUT);
  pinMode(PIR,INPUT);
  Serial.println("***WELCOME TO MY ENERGY CONTROL SYSTEM***");
  
}

void loop()
{
  Serial.print("LDR : ");
  Serial.println(analogRead(LDR));
  Serial.print("PIR : ");
  Serial.println(digitalRead(PIR));
  Serial.print("\n\n");
  delay(1000);
  if(digitalRead(PIR)==HIGH && analogRead(LDR)<100){
    	digitalWrite(led,HIGH);
      	ctr=millis();
  }else if(digitalRead(PIR)==LOW && millis()-ctr>=30000){
    	digitalWrite(led,LOW);
  }
}