int yellowPin=12;
int greenPin=3;
int bluePin=10;
int redPin=6;

int blue_yellow_On=200;
int green_red_On=200;
int blue_yellow_Off=900;
int green_red_Off=900;


void setup() {
    Serial.begin(9600);
    Serial.println("***welcome to my program***");
    pinMode(yellowPin,OUTPUT);
    pinMode(greenPin,OUTPUT);
    pinMode(bluePin,OUTPUT);
    pinMode(redPin,OUTPUT);
}

void loop() {
  
  for(int i=1; i <=3; i++){
    Serial.print("  You are in YELLOW and BLUE blink ");
    Serial.println(i);
    digitalWrite(yellowPin,HIGH);
    digitalWrite(bluePin,HIGH);
    delay(blue_yellow_On);
    digitalWrite(yellowPin,LOW);
    digitalWrite(bluePin,LOW);
    delay(blue_yellow_Off);
  }
  Serial.println(" ");
  for(int j=1; j<=3; j++) {
    Serial.print("  You are in GREEN and RED blink ");
    Serial.println(j);
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,HIGH);
    delay(green_red_On);
    digitalWrite(greenPin,LOW);
    digitalWrite(redPin,LOW);
    delay(green_red_Off);
  }

  

}
