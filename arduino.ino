#include <AFMotor.h>
AF_DCMotor bottom(1); // create motor #2
AF_DCMotor left(3); //left
AF_DCMotor right(4); //right
AF_DCMotor clip(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  bottom.setSpeed(200);     // set the speed to 200/255
  left.setSpeed(255);
  right.setSpeed(255);
  clip.setSpeed(200);
}

int stopTime = 1950;
int i = 0;

void moveDown(){
    left.run(FORWARD);
    delay(stopTime);
    left.run(RELEASE);
    delay(1000);
}

void moveUp(){
    left.run(BACKWARD);
    delay(stopTime);
    left.run(RELEASE);
    delay(1000);
}

void moveAhead(){
  right.run(FORWARD);
  delay(stopTime);
  right.run(RELEASE);
  delay(1000);
}

void moveBack(){
  right.run(BACKWARD);
  delay(stopTime);
  right.run(RELEASE);
  delay(1000);
}

void clipOpen(){
    clip.run(FORWARD);
    delay(1000);
    clip.run(RELEASE);
    delay(1000);
}

void leftMove(){
  bottom.run(FORWARD);
    delay(3000);
    bottom.run(RELEASE);
    delay(1000);
}

void rightMove(){
  bottom.run(BACKWARD);
    delay(3000);
    bottom.run(RELEASE);
    delay(1000);
}

void closeClip(){
  clip.run(BACKWARD);
    delay(7000);
    clip.run(RELEASE);
    delay(1000);
}

void loop() {
  if(i <= 0){
    moveUp();
    clipOpen();
    closeClip();
    leftMove();
//    clipOpen();
//    closeClip();
//    leftMove();
//   moveDown();
//    clipOpen();
//    closeClip();
//    moveUp();
    rightMove();
    clipOpen();
    closeClip();
    rightMove();
    i++;
  }
    
}
