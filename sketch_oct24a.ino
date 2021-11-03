const int pinphotoR  = 4;
const int inputPhotoR  = A0;
const int pinButton=7;
const int ledButton=8;
  int valButtonIn;
#define trigPin A1

#define echoPin A2

#define ledUltrasonic 3


void setup() {
  Serial.begin (9600);
//  button  
pinMode(pinButton, INPUT);
pinMode(ledButton, OUTPUT);
//photoR 
pinMode(pinphotoR, OUTPUT);
pinMode(inputPhotoR, INPUT);
// ultrasonic
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledUltrasonic, OUTPUT);
}

void loop() {
buttonPlace();
photoR();
ultrasonic();


}
void buttonPlace(){
  valButtonIn=digitalRead(pinButton);
  if(valButtonIn==HIGH){
  digitalWrite(ledButton, HIGH);
  }else{
   digitalWrite(ledButton, LOW);

  }
  Serial.print(valButtonIn);
 //  digitalWrite(pinButton, HIGH);  
}
void photoR(){
  int val;
  val = analogRead(inputPhotoR);

  if(val <= 150){
    digitalWrite(pinphotoR, HIGH);    
   }else{
      digitalWrite(pinphotoR, LOW);    
    }
  
  
  }

void ultrasonic(){
long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

if (distance < 10)

{ digitalWrite(ledUltrasonic,LOW);

}

else {

digitalWrite(ledUltrasonic,HIGH);

}




  
  }  
