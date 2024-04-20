 
#include <Servo.h>

Servo myservo1; 
Servo myservo2;

int relayPin1=D5;
int relayPin2=D6;
void setup() {
  //setting pins for 2 pest pumps in D5, D6 
  pinMode(relayPin1,OUTPUT);
  pinMode(relayPin2,OUTPUT);
  digitalWrite(relayPin1,HIGH);
  digitalWrite(relayPin2,HIGH);


  Serial.begin(9600);
  //setting servo motors for hand vertical and horizontal movement
  myservo1.attach(D3);
  myservo2.attach(D4);
//  int sprayflag=0;//getting data from thingspeak
  
  // if sprayFlag is greater then 0 then we need to spray 
 
}


void loop() {
  int sprayflag=2; 
// if(sprayflag>=1){
 int moveUp=45;//reading y axis reading from thingspeak
 int moveleft=50;//reading x axis reading form thingspeak
  moveVertical(moveUp);//activating servo motor to move in y axis
  delay(1000);
moveHorizontal(moveleft);//activating servo motor to move in x axis
int typeofspray=sprayflag;
Activatepump(typeofspray);//activating pump to spray pest
//  }
delay(4000);
}
//function to move hand in y axis 
void moveVertical(int val){
  int MoveUP=val;
  for(int i =0 ; i<=MoveUP;i++){
    myservo1.write(i);
    delay(50);
    Serial.print(" u reached");
    Serial.println(i);
    
  }
  
}
// function to move hand in x axis
void moveHorizontal(int val){
  int MoveLeft=val;
  for(int i =0 ; i<=MoveLeft;i++){
    myservo2.write(i);
    delay(50);
     Serial.print(" l reached");
    Serial.println(i);
  }
  
}
//function to activate pump of pest which need to be sprayed
void Activatepump(int val){
// if(val==1){
     digitalWrite(relayPin1,LOW);
  delay(2000);
  digitalWrite(relayPin1,HIGH);  

//  }
//  else if(val==2 ){
   digitalWrite(relayPin2,LOW);
  delay(2000);
  digitalWrite(relayPin2,HIGH);  
  
//    }
 
//    moveToNextPlant();
     
}
