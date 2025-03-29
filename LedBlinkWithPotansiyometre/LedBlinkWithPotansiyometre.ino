int potansiyometre=A0;//potansiyometrenin bağlı olduğu analog pin.
int value=0;//potansiyometreden okunacak değerler. 
int redPin=9,greenPin=6;
int on=900,off=450;

void setup() {
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
}

void loop() {
  value=analogRead(potansiyometre);
  int brightness=map(value,0,1023,0,255);//map(), bir değeri belirli bir aralıktan başka bir aralığa ölçeklendirmek için kullanılır.
  if(brightness<=30){
    analogWrite(redPin,brightness);//belirlenen brightness değerinde red led'i yak.
    Serial.print("Red LED's brightness : ");
    Serial.println(brightness);
    delay(on);
    analogWrite(redPin,0);
    delay(off);
  }
  else{
    analogWrite(greenPin,brightness);
    Serial.print("Green LED's brightness : ");
    Serial.println(brightness);
    delay(on);
    analogWrite(greenPin,0);
    delay(off);
  }
}
