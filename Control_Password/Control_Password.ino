int redPin=10,greenPin=5;
int on=900,off=450;
int temp;

int getPassword(){
  while(Serial.available()==0){}//password girilene kadar bekle.
  int correctPassword=Serial.parseInt();//şifreyi user'dan al.
  return correctPassword;//şifreyi döndür.
}

void setup()
{
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin,OUTPUT);
  Serial.println("***WELCOME TO MY PROGRAM***");
  Serial.print("determine the password(four digit): ");
  temp=getPassword();
  Serial.println("password is entered.");
  
  for(int i=1;i<=5;i++){
    Serial.print("enter correct password: ");
    int enteredPassword=getPassword();
    Serial.println(enteredPassword);
    if(temp==enteredPassword){
      Serial.println("login is successfull.");
      digitalWrite(greenPin,HIGH);
      delay(on);
      digitalWrite(greenPin,LOW);
      delay(off);
      break;
    }
    else{
      Serial.print("Last ");
      Serial.print(5-i);
      Serial.println(" rights.");
      if((5-i)==0){
        Serial.println("login is failed.");
      }
      digitalWrite(redPin,HIGH);
      delay(on);
      digitalWrite(redPin,LOW);
      delay(off);
    }
  }
}

void loop()
{
}