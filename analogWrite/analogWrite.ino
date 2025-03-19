/*analogWrite() fonksiyonu, Arduino'da bir pine PWM (Pulse Width Modulation - Darbe Genişlik Modülasyonu) sinyali göndermek için kullanılır.
***analogWrite() Ne İşe Yarar?
1-Dijital bir pine analog benzeri bir çıkış sinyali üretir.
2-LED parlaklığını ayarlamak, motor hızını kontrol etmek gibi uygulamalarda kullanılır.
3-Gerçek bir analog çıkış sağlamaz, sadece dijital sinyalin yüksek ve düşük seviyeleri arasındaki süreyi değiştirerek analog bir etki oluşturur.
*/

/*PWM NEDİR?-->dijital sinyali kullanarak analog bir etki yaratma yöntemidir.
Dijital sinyaller sadece 0 (LOW) ve 1 (HIGH) olabilir.
PWM, sinyalin 1 (HIGH) olduğu sürenin oranını değiştirerek analog bir çıkış simüle eder.
Bu sayede LED parlaklığı, motor hızı gibi değerler kontrol edilebilir.
*/

/*
 Hangi Pinlerde Kullanılabilir?
Arduino UNO, MEGA ve diğer modellerde PWM destekleyen dijital pinler:
Model	   PWM Pinleri
UNO	      3, 5, 6, 9, 10, 11
MEGA	    2 - 13, 44 - 46
LEONARDO	3, 5, 6, 9, 10, 11, 13
*/


int greenPin=3,yellowPin=11;
int on=900,off=400;
int greenTimes,yellowTimes;
int ledBlink(){
  while(Serial.available()==0){};
  int colourTimes=Serial.parseInt();
  return colourTimes;
}

void setup()
{
  Serial.begin(9600);
  Serial.print("how many times is required for GREEN blink : ");
  greenTimes=ledBlink();
  Serial.println(greenTimes);
  
  Serial.print("how many times is required for YELLOW blink : ");
  yellowTimes=ledBlink();
  Serial.println(yellowTimes);
  
  pinMode(greenPin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
}

void loop()
{
  for(int i=1;i<=greenTimes;i++){
    Serial.print("You are in GREEN blink : ");
    Serial.println(i);
    analogWrite(greenPin, 51);
  	delay(on); 
    analogWrite(greenPin, 0);
  	delay(off);
  }
  Serial.println(" ");
  
  for(int j=1;j<=yellowTimes;j++){
  	Serial.print("You are in YELLOW blink : ");
    Serial.println(j);
    analogWrite(yellowPin,51);
    delay(on);
    analogWrite(yellowPin,0);
    delay(off);
  }
 
}