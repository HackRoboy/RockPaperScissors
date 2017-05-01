#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//600 is the 'maximum' pulse length count (out of 4096)
int pos123 = 600;
int readyPos = 600;

long randNumber; // for turn


////////////////////////////////////////////////////////
///////////////////    CONSTANTS    ///////////////////
////////////////////////////////////////////////////////
const int UNTERES_LIMIT = 170; // this value depends on the adjustment of the servos
const int OBERES_LIMIT = 580; // this value depends on the adjustment of the servos
const int SCHRITTWEITE = 10; // setting up the step size of the servos

// There are two different adresses for the two Adafruit motor boards: pwm & pwm2
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("movement of the roboy hand");
  pwm.begin();
  pwm2.begin();

  randomSeed(analogRead(0));

  // Servos run at ~50 Hz updates
  pwm.setPWMFreq(50);  
  pwm2.setPWMFreq(50); 
  yield();
}

////////////////////////////////////////////////////////
//////////////////    FLEXION_ALL    ///////////////////
////////////////////////////////////////////////////////

void strecken_beugen_alle_gleichzeitig(){
  while(pos123 <= OBERES_LIMIT)
  {
    // indexfinger motors: 10, 11, 12, 13, 14 (pwm board)
    // motor10: stretch, motor11: tilt left, motor12: finger flexion, motor13: fingertip flexion, motor14: tilt right
    pwm.setPWM(10, 0, pos123);   
    pwm.setPWM(11, 0, 600);  
    pwm.setPWM(12, 0, pos123);
    pwm.setPWM(13, 0, pos123);
    pwm.setPWM(14, 0, 600);
    
    // middlefinger motors: 5, 6, 7, 8, 9 (pwm board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm.setPWM(5, 0, pos123);   
    pwm.setPWM(6, 0, 600);  
    pwm.setPWM(7, 0, pos123);
    pwm.setPWM(8, 0, pos123);
    pwm.setPWM(9, 0, 600);

    // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm.setPWM(0, 0, pos123);   
    pwm.setPWM(1, 0, 600);  
    pwm.setPWM(2, 0, pos123);
    pwm.setPWM(3, 0, pos123);
    pwm.setPWM(4, 0, 600);

    // pinky motors: 5, 6, 7, 8, 9 (pwm2 board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm2.setPWM(5, 0, pos123);   
    pwm2.setPWM(6, 0, 600);  
    pwm2.setPWM(7, 0, pos123);
    pwm2.setPWM(8, 0, pos123);
    pwm2.setPWM(9, 0, 600);

    // thumb motors: 0, 1, 2, 3, 4 (pwm2 board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm2.setPWM(0, 0, pos123);   
    pwm2.setPWM(1, 0, 600);  
    pwm2.setPWM(2, 0, pos123);
    pwm2.setPWM(3, 0, pos123);
    pwm2.setPWM(4, 0, 600);
    
    Serial.println("Position beugen alle:");
    Serial.println(pos123);
    pos123 += SCHRITTWEITE; 
  }
}

////////////////////////////////////////////////////////
//////////////////    STRETCH_ALL    ///////////////////
////////////////////////////////////////////////////////

void beugen_strecken_alle_gleichzeitig(){
  while( pos123 >= UNTERES_LIMIT )
  {
    // indexfinger motors: 10, 11, 12, 13, 14 (pwm board)
    // motor10: stretch, motor11: tilt left, motor12: finger flexion, motor13: fingertip flexion, motor14: tilt right
    pwm.setPWM(10, 0, pos123);   
    pwm.setPWM(11, 0, 600);  
    pwm.setPWM(12, 0, pos123);
    pwm.setPWM(13, 0, pos123);
    pwm.setPWM(14, 0, 600);

    // middlefinger motors: 5, 6, 7, 8, 9 (pwm board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm.setPWM(5, 0, pos123);   
    pwm.setPWM(6, 0, 600);  
    pwm.setPWM(7, 0, pos123);
    pwm.setPWM(8, 0, pos123);
    pwm.setPWM(9, 0, 600);

    // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm.setPWM(0, 0, pos123);   // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    pwm.setPWM(1, 0, 600);  
    pwm.setPWM(2, 0, pos123);
    pwm.setPWM(3, 0, pos123);
    pwm.setPWM(4, 0, 600);

    // pinky motors: 5, 6, 7, 8, 9 (pwm2 board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm2.setPWM(5, 0, pos123);   
    pwm2.setPWM(6, 0, 600);  
    pwm2.setPWM(7, 0, pos123);
    pwm2.setPWM(8, 0, pos123);
    pwm2.setPWM(9, 0, 600);

    // thumb motors: 0, 1, 2, 3, 4 (pwm2 board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm2.setPWM(0, 0, pos123);   
    pwm2.setPWM(1, 0, 600);  
    pwm2.setPWM(2, 0, pos123);
    pwm2.setPWM(3, 0, pos123);
    pwm2.setPWM(4, 0, 600);

    
    Serial.println("Position beugen alle:");
    Serial.println(pos123);
    pos123 -= SCHRITTWEITE;
  }
}

////////////////////////////////////////////////////////
//////////////////    PREPARE    ///////////////////
////////////////////////////////////////////////////////

void ready_three() {
  readyPos = pos123;
  while( readyPos >= UNTERES_LIMIT )
  {
    // indexfinger motors: 10, 11, 12, 13, 14 (pwm board)
    // motor10: stretch, motor11: tilt left, motor12: finger flexion, motor13: fingertip flexion, motor14: tilt right
    pwm.setPWM(10, 0, readyPos);   
    pwm.setPWM(11, 0, 600);  
    pwm.setPWM(12, 0, readyPos);
    pwm.setPWM(13, 0, readyPos);
    pwm.setPWM(14, 0, 600);

    // middlefinger motors: 5, 6, 7, 8, 9 (pwm board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm.setPWM(5, 0, readyPos);   
    pwm.setPWM(6, 0, 600);  
    pwm.setPWM(7, 0, readyPos);
    pwm.setPWM(8, 0, readyPos);
    pwm.setPWM(9, 0, 600);

    // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm.setPWM(0, 0, readyPos);   // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    pwm.setPWM(1, 0, 600);  
    pwm.setPWM(2, 0, readyPos);
    pwm.setPWM(3, 0, readyPos);
    pwm.setPWM(4, 0, 600);

    Serial.println("Position beugen alle:");
    Serial.println(pos123);
    readyPos -= SCHRITTWEITE; 
  }

  delay(1000);

  pos123 = readyPos;
  while(readyPos <= OBERES_LIMIT)
  {
    // ringfinger motors: 0, 1, 2, 3, 4 (pwm board)
    // motor0: stretch, motor1: tilt left, motor2: finger flexion, motor3: fingertip flexion, motor4: tilt right
    pwm.setPWM(0, 0, readyPos);   
    pwm.setPWM(1, 0, 600);  
    pwm.setPWM(2, 0, readyPos);
    pwm.setPWM(3, 0, readyPos);
    pwm.setPWM(4, 0, 600);
    
    Serial.println("Position beugen alle:");
    Serial.println(readyPos);
    readyPos += SCHRITTWEITE; 
  }

  delay(1000);

  readyPos = pos123;
  while(readyPos <= OBERES_LIMIT)
  {
    // middlefinger motors: 5, 6, 7, 8, 9 (pwm board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm.setPWM(5, 0, readyPos);   
    pwm.setPWM(6, 0, 600);  
    pwm.setPWM(7, 0, readyPos);
    pwm.setPWM(8, 0, readyPos);
    pwm.setPWM(9, 0, 600);
    
    Serial.println("Position beugen alle:");
    Serial.println(readyPos);
    readyPos += SCHRITTWEITE; 
  }

  delay(1000);

  readyPos = pos123;
  while(readyPos <= OBERES_LIMIT)
  {
    // indexfinger motors: 10, 11, 12, 13, 14 (pwm board)
    // motor10: stretch, motor11: tilt left, motor12: finger flexion, motor13: fingertip flexion, motor14: tilt right
    pwm.setPWM(10, 0, readyPos);   
    pwm.setPWM(11, 0, 600);  
    pwm.setPWM(12, 0, readyPos);
    pwm.setPWM(13, 0, readyPos);
    pwm.setPWM(14, 0, 600);
    
    Serial.println("Position beugen alle:");
    Serial.println(readyPos);
    readyPos += SCHRITTWEITE; 
  }

  pos123 = readyPos;
}

////////////////////////////////////////////////////////
//////////////////    READY-STEADY-GO    ///////////////////
////////////////////////////////////////////////////////
void ready_steady_go(){
  strecken_beugen_alle_gleichzeitig();
  delay(1000);
  beugen_strecken_alle_gleichzeitig();
  delay(1000);
}

////////////////////////////////////////////////////////
//////////////////    STONE    ///////////////////
////////////////////////////////////////////////////////
void make_stone() {
  beugen_strecken_alle_gleichzeitig();
}

////////////////////////////////////////////////////////
//////////////////    PAPPER    ///////////////////
////////////////////////////////////////////////////////
void make_papper() {
  strecken_beugen_alle_gleichzeitig();
}

////////////////////////////////////////////////////////
//////////////////    SCISSORS    ///////////////////
////////////////////////////////////////////////////////
void make_scissors() {
  while( readyPos >= UNTERES_LIMIT )
  {
    // indexfinger motors: 10, 11, 12, 13, 14 (pwm board)
    // motor10: stretch, motor11: tilt left, motor12: finger flexion, motor13: fingertip flexion, motor14: tilt right
    pwm.setPWM(10, 0, readyPos);   
    pwm.setPWM(11, 0, 600);  
    pwm.setPWM(12, 0, readyPos);
    pwm.setPWM(13, 0, readyPos);
    pwm.setPWM(14, 0, 600);

    // middlefinger motors: 5, 6, 7, 8, 9 (pwm board)
    // motor5: stretch, motor6: tilt left, motor7: finger flexion, motor8: fingertip flexion, motor9: tilt right
    pwm.setPWM(5, 0, readyPos);   
    pwm.setPWM(6, 0, 600);  
    pwm.setPWM(7, 0, readyPos);
    pwm.setPWM(8, 0, readyPos);
    pwm.setPWM(9, 0, 600);

    Serial.println("Position beugen alle:");
    Serial.println(pos123);
    readyPos -= SCHRITTWEITE; 
  }
}

void make_turn() {
  randNumber = random(3);
//randNumber = 2;
  Serial.println(randNumber);
  switch (randNumber) {
    case 0:
      make_stone();
      break;
    case 1:
      make_papper();
      break;
    case 2:
      make_scissors();
      break;
  }
}


void loop() {
  readyPos = 600;
  beugen_strecken_alle_gleichzeitig(); // movement from flexion to stretch
  delay(2000);
  strecken_beugen_alle_gleichzeitig(); // movement from stretch to flexion
  delay(2000);
  ready_three();
  delay(1000);
  make_turn();
  delay(5000);
}


