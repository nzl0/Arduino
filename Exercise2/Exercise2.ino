int LDR=A0,POT=A2,button=8,buzzer=2;
bool process=false;
struct RGBLed{
  int redPin;
  int greenPin;
  int bluePin;
};
struct SystemValues{
  bool process=false;
  int light=0;
  int brightness=0;
};

 RGBLed rgb={11,6,3};
 SystemValues values;

void controlLight(int light,int brightness){
      Serial.print("light : ");
      Serial.println(values.light);
      Serial.print("brightness : ");
      Serial.println(values.brightness);
  if(light<5){
    analogWrite(rgb.redPin,values.brightness);
    analogWrite(rgb.bluePin,values.brightness);
    analogWrite(rgb.greenPin,values.brightness);
    delay(1000);
  }else{
    analogWrite(rgb.redPin,0);
    analogWrite(rgb.bluePin,0);
    analogWrite(rgb.greenPin,250);
    delay(1000);
  }
}

void controlDanger(){
    digitalWrite(buzzer,HIGH);
    analogWrite(rgb.redPin,250);
    analogWrite(rgb.bluePin,0);
    analogWrite(rgb.greenPin,0);
    delay(2000);
}

void clearSerial(){
  while(Serial.available() > 0){
    Serial.read();
  }
}

int arrangeBrightness(){
  Serial.print("what is brightness that you desire(0,255)  :");
  while(Serial.available()==0){}
  int brightness_value=Serial.parseInt();
  values.brightness=brightness_value;
  clearSerial();
  return values.brightness;
}

void controlSystem(int input){
      values.light=analogRead(LDR);
      int value=analogRead(POT);
      values.brightness=map(value,0,1023,0,255);
  switch(input){
    case 1 : 
      values.process=true;
      
      controlLight(values.light,values.brightness);
      break;
    case 2 :
      analogWrite(rgb.redPin,0);
      analogWrite(rgb.greenPin,0);
      analogWrite(rgb.bluePin,0);
      digitalWrite(buzzer,LOW);
      delay(1000);
      break;

    case 3 :
      if(values.process){
        Serial.print("Selected brightness : ");
        int value=arrangeBrightness();
        Serial.println(value);
        controlLight(values.light,value);
      }else{
        Serial.println("Firstly, you should open the system.");
      }
      break;
    case 4 :
      if(values.process){
        controlDanger();
        digitalWrite(buzzer,LOW);
      }else{
        Serial.println("Firstly, you should open the system.");
      }
      break;
    
    default:
      Serial.println("invalid value");
  }
}



void setup() {
  Serial.begin(9600);
  pinMode(rgb.redPin,OUTPUT);
  pinMode(rgb.greenPin,OUTPUT);
  pinMode(rgb.bluePin,OUTPUT);
  pinMode(button,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.println("***WELCOME TO MY SYSTEM***");
}

void loop() {
  Serial.println("Select one of them : ");
  Serial.println("1.Open the system\n2.Close the system\n3.Determine the brightness\n4.Take active the button.");
  while(Serial.available()==0) {}
    int number =Serial.parseInt();
    clearSerial();
    Serial.print("Your choice : ");
    Serial.println(number);
    controlSystem(number);
}

  


