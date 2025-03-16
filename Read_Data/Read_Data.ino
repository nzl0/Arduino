/*
Serial.available() fonksiyonu, seri port üzerinden gelen verileri kontrol etmek için kullanılır. 
Arduino'nun seri portuna bağlı bir cihazdan (bilgisayar, başka bir Arduino veya sensör gibi) veri gelip gelmediğini anlamanı sağlar.
Serial.available() fonksiyonu, seri portta bekleyen bayt sayısını (gelen veri miktarını) döndürür.
Eğer 0 döndürüyorsa, seri portta okunacak veri yoktur.
Eğer 0'dan büyük bir değer döndürüyorsa, o kadar bayt okunabilir veri vardır.
*/

int yellowPin=12;
int greenPin=3;
int bluePin=10;
int redPin=6;

int redTimes;
int blueTimes;
int greenTimes;
int yellowTimes;

int on=100,off=900;

void clearBuffer(){
  while(Serial.available()>0){
    Serial.read();//clean the buffer
  }
}

int ledBlink(){
  while(Serial.available()==0){}
  int colourTimes=Serial.parseInt();
  clearBuffer();
  return colourTimes;
}

void setup() {
  Serial.begin(9600);
  pinMode(yellowPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(redPin,OUTPUT);
 
  Serial.println("***welcome to my program***");

  Serial.print("How many times is required for yellow blink : ");
  yellowTimes=ledBlink();
  Serial.println(yellowTimes);

  Serial.print("How many times is required for green blink : ");
  greenTimes=ledBlink();
  Serial.println(greenTimes);

  Serial.print("How many times is required for blue blink : ");
  blueTimes=ledBlink();
  Serial.println(blueTimes);

  Serial.print("How many times is required for red blink : ");
  redTimes=ledBlink();
  Serial.println(redTimes);
}

void loop() {
  
  for(int i=1;i<=yellowTimes;i++){
    Serial.print(" You are in YELLOW blink : ");
    Serial.println(i);
    digitalWrite(yellowPin,HIGH);
    delay(on);
    digitalWrite(yellowPin,LOW);
    delay(off);
  }
  Serial.println(" ");

  for(int j=1; j<=greenTimes; j++){
    Serial.print(" You are in GREEN blink : ");
    Serial.println(j);
    digitalWrite(greenPin,HIGH);
    delay(on);
    digitalWrite(greenPin,LOW);
    delay(off);
  }
  Serial.println(" ");

  for(int k=1; k<=blueTimes; k++){
    Serial.print(" You are in BLUE blink : ");
    Serial.println(k);
    digitalWrite(bluePin,HIGH);
    delay(on);
    digitalWrite(bluePin,LOW);
    delay(off);
  }
  Serial.println(" ");

  for(int m=1;m<=redTimes; m++){
    Serial.print(" You are in RED blink  :");
    Serial.println(m);
    digitalWrite(redPin,HIGH);
    delay(on);
    digitalWrite(redPin,LOW);
    delay(off);
  }
}
