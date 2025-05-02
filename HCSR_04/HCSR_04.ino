int trigPin=4,echoPin=2,buzzer=13;
void setup() {
  Serial.begin(9600);
  Serial.println("***WELCOME TO DISTANCE SYSTEM***");
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
   digitalWrite(trigPin,LOW);
   delayMicroseconds(2);
   Serial.println("starting...");
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);

   long time=pulseIn(echoPin,HIGH,30000);
   float distance;
   if(time==0){
    distance=0.0;
    Serial.println("mistake... ");
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
   }else{
    distance=time * 0.034 / 2;
    Serial.print("distance: ");
    Serial.print(distance);
    Serial.println(" cm");
   }
   
   delay(500);
}
