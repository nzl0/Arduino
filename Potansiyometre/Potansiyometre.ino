int potansiyometre=A0;//potansiyometrenin hangi analog pine bağlı olduğu belirtildi.
int value=0;//potansiyometreden okunacak değerler bu değişkende tutulacak.

void setup() {
  Serial.begin(9600);
}

void loop() {
  value=analogRead(potansiyometre);//potansiyomtereden gelen değerler value değişkenine atandı.0-1023 arası bir değer okur, çünkü arduino 10 bitlik bir ADC kullanır.(2^10=1024)
  Serial.print("value came from potansiyometre : ");
  Serial.println(value);//potansiyometrenin sürgüsü döndürülürse bu değer değişecektir.
  delay(1000);
}
