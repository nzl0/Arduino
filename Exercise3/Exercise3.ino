#include <LiquidCrystal.h>
int led=8;//dijital output
int LDR=A0; //analog input
int PIR=13; //dijital output
int TMP=A1;
unsigned long ctr=0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);
  Serial.println("WELCOME");
  
  lcd.begin(16,2);
  lcd.print("WELCOME!");
  
  pinMode(led,OUTPUT);
  pinMode(LDR,INPUT);
  pinMode(PIR,INPUT);

}

void loop()
{
  Serial.print("LDR : ");
  Serial.println(analogRead(LDR));
  Serial.print("PIR : ");
  Serial.println(digitalRead(PIR));
  Serial.print("\n\n");
  
  if(digitalRead(PIR)==HIGH && analogRead(LDR)<100){
    	digitalWrite(led,HIGH);
      	ctr=millis();
  }else if(digitalRead(PIR)==LOW && millis()-ctr>=1000){
    	digitalWrite(led,LOW);
  }
  
  float voltaj=analogRead(TMP)*(5.0/1023.0);//analog değer voltaja çevrildi.
  float temp=(voltaj-0.5)*100.0;
  
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("move: ");
  lcd.print(digitalRead(PIR));
  delay(500);

}