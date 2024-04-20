import RPi.GPIO as GPIO
from time import sleep
from gpiozero import AngularServo


# Define GPIO pin numbers
ENA = 17
ENB = 27
IN_1 =22
IN_2 = 6
IN_3 = 5
IN_4 =26

#define Gpio pin for relay
relayPin1 = 24
relayPin2 = 23 



GPIO.setwarnings(False)
# Initialize GPIO pins
GPIO.setmode(GPIO.BCM)
GPIO.setup(ENA, GPIO.OUT)
GPIO.setup(ENB, GPIO.OUT)
GPIO.setup(IN_1, GPIO.OUT)
GPIO.setup(IN_2, GPIO.OUT)
GPIO.setup(IN_3, GPIO.OUT)
GPIO.setup(IN_4, GPIO.OUT)
GPIO.setup(relayPin1, GPIO.OUT)
GPIO.setup(relayPin2, GPIO.OUT)
#declaring servo
servo1 =AngularServo(13, min_angle=0, max_angle=180, min_pulse_width=0.0005, max_pulse_width=0.0025)
servo2 =AngularServo(12, min_angle=0, max_angle=180, min_pulse_width=0.0005, max_pulse_width=0.0025)

# Initial settings
speedCar = 800
speed_Coeff = 3


#this function starts the movement of robot in forward 
def goAhead():
    GPIO.output(IN_1, GPIO.LOW)
    GPIO.output(IN_2, GPIO.HIGH)
    GPIO.output(ENA, GPIO.HIGH)
    
    GPIO.output(IN_3, GPIO.LOW)
    GPIO.output(IN_4, GPIO.HIGH)
    GPIO.output(ENB, GPIO.HIGH)


#this function stops the robot
def stopRobot():
    GPIO.output(IN_1, GPIO.LOW)
    GPIO.output(IN_2, GPIO.LOW)
    GPIO.output(ENA, GPIO.HIGH)
    
    GPIO.output(IN_3, GPIO.LOW)
    GPIO.output(IN_4, GPIO.LOW)
    GPIO.output(ENB, GPIO.HIGH)
# this function controls the vertical movement of servo 
def moveVertical(val):
    MoveUP = val_to_range(val,0,180,0,180)
    for i in range(0,MoveUP):
        servo1.angle=i
        sleep(0.05)

# this function controls the horizontal movement of servo 
def moveHorizontal(val):
    MoveLeft = val_to_range(val,0,180,0,180)
    for i in range(0,MoveLeft):
        servo2.angle=MoveLeft
        sleep(0.05)


#this function is used to control the pumps according to value passed
def Activatepump(val):
    if val == 1:
        GPIO.output(relayPin1, GPIO.LOW)
        time.sleep(2)
        GPIO.output(relayPin1, GPIO.HIGH)
        time.sleep(2)
    elif val == 2:
        GPIO.output(relayPin2, GPIO.LOW)
        time.sleep(2)
        GPIO.output(relayPin2, GPIO.HIGH)
        time.sleep(2)


#this function maps the value in servo angle range
def val_to_range(val,currMin,currMax,finalMin,finalMax):
     proportion=(val -currMin)/(currMax-currMin)
     newVal=finalMin + proportion * (finalMax - finalMin)
     return newVal




#this is main function that is needed to be called after the prediction
#to control the iot components
def mainIOt(sprayType,verticalMovement,horizontalMovement):
        sprayflag = sprayType #0=>no spray 1=>type1 spray 2=>type2 spray
        moveUp = verticalMovement  # Replace with your y-axis reading
        moveleft = horizontalMovement # Replace with your x-axis reading
        if(spray>0):
            moveVertical(moveUp)
            time.sleep(1)
            moveHorizontal(moveleft)
            time.sleep(1)
            typeofspray = sprayflag
            Activatepump(typeofspray)
            time.sleep(1)

            moveVertical(0)
            time.sleep(1)
            moveHorizontal(0)
            time.sleep(1)
            goAhead()
            time.sleep(2)
            stopRobot()
        else:
            goAhead()
            time.sleep(2)
            stopRobot()

