int redPin=10,greenPin=6,bluePin=3;
String colour;
void setup() {
 Serial.begin(9600);
 pinMode(redPin,OUTPUT);
 pinMode(greenPin,OUTPUT);
 pinMode(bluePin,OUTPUT);
}

void loop() {
  Serial.println("****Welcome To Mood Light****");
  Serial.print("Which colour red or green or blue : ");
  while(Serial.available()==0){} //renk girilene kadar bekle.
  colour=Serial.readString(); //kullanıcıdan renk alındı.
  colour.trim(); //colour stringinde boşluk varsa temizle.
  Serial.print(colour);
  Serial.print("\n");

  if(colour.equals("red")){ //eğer renk red ise
    Serial.println("mood light");
    for(int i=255;i>=0;i-=5){
      analogWrite(redPin,i); //red rengini en son parlaklıktan sönene kadar yak.
      delay(100);
      analogWrite(greenPin,255-i); //green rengini sönük halden en yüksek parlaklığa kadar yak.
      delay(100);
    }
    for(int i=255;i>=0;i-=5){
      analogWrite(greenPin,i); //green rengini en son parlaklıktan sönene kadar yak.
      delay(100);
      analogWrite(bluePin,255-i); //blue rengini sönük halden en yüksek parlaklığa kadar yak.
      delay(100);
    }
    for(int i=255;i>=0;i-=5){
      analogWrite(bluePin,i); //blue rengini en son parlaklıktan sönene kadar yak.
      delay(100);
      analogWrite(redPin,255-i); //red rengini sönük halden en yüksek parlaklığa kadar yak.
      delay(100);
    }
  }
  else if(colour.equals("blue")){ //renk blue ise sadece blue yakar.
    analogWrite(bluePin,150);
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
  }
  else if(colour.equals("green")){ //renk green ise sadece green yakar.
    analogWrite(greenPin,150);
    analogWrite(bluePin,0);
    analogWrite(redPin,0);
  }
  else{
    Serial.println("You should any colour from red or green or blue!!"); //geçersiz bir renk veya karakter durumunda ekrana yazdır.
  }

  delay(1000); //bir sonraki renk komutunu alana kadar 1 saniye(1000 milisaniye) bekle.
}