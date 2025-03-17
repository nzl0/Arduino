
int greenPin=10;
int whitePin=2;

int on=100,off=900;
int ctr1=1;
int ctr2=1;

int greenTimes,whiteTimes;
int ledBlink(){
  while(Serial.available()==0){}//wait to enter
  int colourTimes=Serial.parseInt();
  return colourTimes;
}


void setup()
{
  Serial.begin(9600);
  
  Serial.print("How many times is required to GRREN blink : ");
  greenTimes=ledBlink();
  Serial.println(greenTimes);
  
  Serial.print("How many times is required to WHITE blink : ");
  whiteTimes=ledBlink();
  Serial.println(whiteTimes);
  
  pinMode(greenPin, OUTPUT);
  pinMode(whitePin,OUTPUT);
}

void loop()
{
  
  while(ctr1<=greenTimes){
    Serial.print(" You are in GREEN blink : ");
    Serial.println(ctr1);
    digitalWrite(greenPin, HIGH);
  	delay(on); 
  	digitalWrite(greenPin, LOW);
  	delay(off);
    ctr1++;
  }
  
  Serial.println(" ");
  
  while(ctr2<=whiteTimes){
    Serial.print(" You are in WHITE blink : ");
    Serial.println(ctr2);
    digitalWrite(whitePin,HIGH);
    delay(on);
    digitalWrite(whitePin,LOW);
    delay(off);
    ctr2++;
  }
}