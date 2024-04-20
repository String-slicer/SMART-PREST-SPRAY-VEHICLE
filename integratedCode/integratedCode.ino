#define ENA   14          // Enable/speed motors Right        GPIO14(D5)
#define ENB   12          // Enable/speed motors Left         GPIO12(D6)
#define IN_1  15          // L298N in1 motors Right           GPIO15(D8)
#define IN_2  13          // L298N in2 motors Right           GPIO13(D7)
#define IN_3  2           // L298N in3 motors Left            GPIO2(D4)
#define IN_4  0           // L298N in4 motors Left            GPIO0(D3)
#include <Servo.h>

int speedCar = 800;         // 400 - 1023.
int speed_Coeff = 3;


Servo myservo1; 
Servo myservo2;
int relayPin1=D2;//rx
int relayPin2=D1;
void setup() {
  // put your setup code here, to run once:
//  pinMode(relayPin1,FUNCTION_3);
   pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT);  
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT); 
  pinMode(relayPin1,OUTPUT);
  pinMode(relayPin2,OUTPUT);
  
    myservo1.attach(D0);
  myservo2.attach(3);
 Serial.begin(115200);
 

}
void goAhead(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
//    stopRobot(); 
     
  }
  void stopRobot(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA,speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
 }


void loop() {
  int sprayflag=2; 
// if(sprayflag>=1){
 int moveUp=90;//reading y axis reading from thingspeak
 int moveleft=90;//reading x axis reading form thingspeak
  moveVertical(moveUp);//activating servo motor to move in y axis
  delay(1000);
moveHorizontal(moveleft);//activating servo motor to move in x axis
delay(1000);
int typeofspray=sprayflag;
Activatepump(typeofspray);//activating pump to spray pest
//  }

delay(1000);
goAhead();
delay(2000);
stopRobot();
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
   delay(2000); 
//  }
//  else if(val==2 ){
   digitalWrite(relayPin2,LOW);
  delay(2000);
  digitalWrite(relayPin2,HIGH);  
  
//    }
 
//    moveToNextPlant();
     
}
