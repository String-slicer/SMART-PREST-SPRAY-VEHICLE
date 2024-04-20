 
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards

Servo myservo2;
int servopin1=D3;
int servopin2=D4;
void setup() {
  Serial.begin(9600);
  myservo1.attach(servopin1);
 myservo2.attach(servopin2);
 

}

void loop() { 
 moveVertical(90);
//  delay(1000);
moveHorizontal(180);
}
void moveVertical(int val){
//  int MoveUP=map(val,y0,yn,0,180);
  int MoveUP=val;
  for(int i =0 ; i<=MoveUP;i++){
    myservo1.write(i);
    delay(10);
    Serial.print(" u reached");
    Serial.println(i);
    
  }
  
}
void moveHorizontal(int val){
//  int MoveLeft=map(val,x0,xn,0,180);
  int MoveLeft=val;
  for(int i =0 ; i<=MoveLeft;i++){
    myservo2.write(i);
    delay(10);
     Serial.print(" l reached");
    Serial.println(i);
  }
  
}
