// Created by Luis Saborio H.
/*
  This is an arm used to control an application developed
 for mobile devices, such as smartphones and tablets, this
 arm has to support 3 different screen resolutions and 
 press buttons from 0 to 9 in an specific order
 */
#include <Servo.h>

Servo servoPress, servoFinger, servoSpin;

int posX = 90, posY = 0, spin= 90;

int btn = 0, screenResolution = 0, pressTime = 0, force = 20, downSpeed = 20, pressBtn = 0, backSpeed = 20;

/*
  This function is used to set de configuration of the arduino
 */
void setup() {
  servoFinger.attach(9);
  servoSpin.attach(10);
  servoPress.attach(11);
  back(); // Put the finger in the start position
  Serial.begin(9600);
  delay(1000);  // Wait 1 second to start the execution
}

/*
  This function is a loop that manage all the incoming data from the device driver
 */
void loop() {

  //***Manual Calibration**************************************************************
    if (Serial.available() > 0)
//    {
//      back();
//      
//      posX = Serial.parseInt();
//      spin = Serial.parseInt();
//      posY = Serial.parseInt();
//      pressTime = 0;
//      
//      Serial.print(posX);
//      Serial.print(",");
//      Serial.print(spin);
//      Serial.print(",");
//      Serial.println(posY);
//      moveFinger(posX);
//      moveSpin(spin);
//      movePress(posY);
//  
//      delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
//      back();
//    }
  //***********************************************************************************

  //***Proyect code********************************************************************
  //  Serial.print(servoPress.read());
  //  Serial.print(",");
  //  Serial.print(servoFinger.read());
  //  Serial.print(",");
  //  Serial.println(servoSpin.read());
  if (Serial.available() > 0)
  {
    btn = Serial.parseInt();              //Read the button it will press
    screenResolution = Serial.parseInt(); //Read the screen resolution
    pressBtn = Serial.parseInt();         //Read if it has to press the button (0 = no, 1 = yes)
    pressTime = Serial.parseInt();        //Read the press time in seconds, 0 if touch
    pressTime = 1000 * pressTime;         //Convertion from ms to s

    switch (btn) {
    case 1:
      button1();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton1(); //Function to press the button
      break;
    case 2:
      button2();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton2(); //Function to press the button
      break;
    case 3:
      button3();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton3(); //Function to press the button
      break;
    case 4:
      button4();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton4(); //Function to press the button
      break;
    case 5:
      button5();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton5(); //Function to press the button
      break;
    case 6:
      button6();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton6(); //Function to press the button
      break;
    case 7:
      button7();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton7(); //Function to press the button
      break;
    case 8:
      button8();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton8(); //Function to press the button
      break;
    case 9:
      button9();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton9(); //Function to press the button
      break;
    case 0:
      button0();        //Function to put the finger in position to press the button
      if(pressBtn)
        pressButton0(); //Function to press the button
      break;
    }
  }
  //***********************************************************************************

}

/*
  Put the finger in the start position.
 */
void back(){
  if(servoPress.read() < 90){
    for (int x = servoPress.read(); x <= 90; x += 1) {  // goes from actual position to 90 degrees
      servoPress.write(x);                              // tell servo to go to position in variable 'x'
      delay(backSpeed);                                        // waits 15ms for the servo to reach the position
    }
  } 
  else {
    for (int x = servoPress.read(); x >= 90; x -= 1) {  // goes from actual position to 90 degrees
      servoPress.write(x);                              // tell servo to go to position in variable 'x'
      delay(backSpeed);                                        // waits 15ms for the servo to reach the position
    }
  }

  for (int x = servoFinger.read(); x >= 0; x -= 1) {    // goes from actual position to 0 degrees
    servoFinger.write(x);                               // tell servo to go to position in variable 'x'
    delay(backSpeed);                                          // waits 15ms for the servo to reach the position
  }

  if(servoSpin.read() < 90){
    for (int x = servoSpin.read(); x <= 90; x += 1) {   // goes from actual position to 90 degrees
      servoSpin.write(x);                               // tell servo to go to position in variable 'x'
      delay(backSpeed);                                        // waits 15ms for the servo to reach the position
    }
  } 
  else {
    for (int x = servoSpin.read(); x >= 90; x -= 1) {   // goes from actual position to 90 degrees
      servoSpin.write(x);                               // tell servo to go to position in variable 'x'
      delay(backSpeed);                                        // waits 15ms for the servo to reach the position
    }
  }

}

/*
  This function do the movement of the press servo
 @param pos is used to set the final position of the finger
 */
void movePress(int pos){
  if(servoPress.read() != pos){              // check if the servo is already in the position
    if(pos > 90){                            // check in which direction it should move
      for (int x = 90; x <= pos; x += 1) {   // goes from 90 degrees to a specific position
        servoPress.write(x);                 // tell servo to go to position in variable 'x'
        delay(downSpeed);                    // waits an specific time (speed) for the servo to reach the position
      }
    } 
    else {
      for (int x = 90; x >= pos; x -= 1) {   // goes from 90 degrees to a specific position
        servoPress.write(x);                 // tell servo to go to position in variable 'x'
        delay(downSpeed);                    // waits an specific time (speed) for the servo to reach the position
      }
    }
  }
}

/*
  This function do the movement of the finger servo
 @param pos is used to set the final position of the finger
 */
void moveFinger(int pos){
  if(servoFinger.read() != pos){             // check if the servo is already in the position
    for (int x = 0; x <= pos; x += 1) {      // goes from 0 degrees to a specific position
      servoFinger.write(x);                  // tell servo to go to position in variable 'x'
      delay(15);                             // waits 15ms for the servo to reach the position
    }
    delay(200);
  }
}

/*
  This function do the movement of the spin servo
 @param pos is used to set the final position of the finger
 */
void moveSpin(int pos){
  if(servoSpin.read() != pos){               // check if the servo is already in the position
    if(pos > 90){                            // check in which direction it should move
      for (int x = 90; x <= pos; x += 1) {   // goes from 90 degrees to a specific position
        servoSpin.write(x);                  // tell servo to go to position in variable 'x'
        delay(15);                           // waits 15ms for the servo to reach the position
      }
    } 
    else {
      for (int x = 90; x >= pos; x -= 1) {   // goes from 90 degrees to a specific position
        servoSpin.write(x);                  // tell servo to go to position in variable 'x'
        delay(15);                           // waits 15ms for the servo to reach the position
      }
    }
    delay(200);
  }
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button1(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(62);
    moveSpin(107);
    break;
  case 2:
    moveFinger(76);
    moveSpin(114);
    break;
  case 4:
    moveFinger(77);
    moveSpin(115);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton1(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(177);
    break;
  case 2:
    movePress(179);
    break;
  case 4:
    movePress(180);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button2(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(62);
    moveSpin(101);
    break;
  case 2:
    moveFinger(74);
    moveSpin(99);
    break;
  case 4:
    moveFinger(74);
    moveSpin(99);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton2(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(177);
    break;
  case 2:
    movePress(180);
    break;
  case 4:
    movePress(178);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button3(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(62);
    moveSpin(92);
    break;
  case 2:
    moveFinger(75);
    moveSpin(86);
    break;
  case 4:
    moveFinger(81);
    moveSpin(84);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton3(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(178);
    break;
  case 2:
    movePress(180);
    break;
  case 4:
    movePress(182);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button4(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(54);
    moveSpin(109);
    break;
  case 2:
    moveFinger(61);
    moveSpin(116);
    break;
  case 4:
    moveFinger(63);
    moveSpin(118);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton4(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(177);
    break;
  case 2:
    movePress(178);
    break;
  case 4:
    movePress(180);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button5(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(54);
    moveSpin(101);
    break;
  case 2:
    moveFinger(57);
    moveSpin(99);
    break;
  case 4:
    moveFinger(56);
    moveSpin(99);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton5(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(175);
    break;
  case 2:
    movePress(175);
    break;
  case 4:
    movePress(172);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button6(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(54);
    moveSpin(92);
    break;
  case 2:
    moveFinger(61);
    moveSpin(85);
    break;
  case 4:
    moveFinger(61);
    moveSpin(85);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton6(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(177);
    break;
  case 2:
    movePress(178);
    break;
  case 4:
    movePress(180);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button7(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(46);
    moveSpin(109);
    break;
  case 2:
    moveFinger(46);
    moveSpin(116);
    break;
  case 4:
    moveFinger(44);
    moveSpin(122);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton7(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(174);
    break;
  case 2:
    movePress(175);
    break;
  case 4:
    movePress(175);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button8(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(46);
    moveSpin(101);
    break;
  case 2:
    moveFinger(45);
    moveSpin(99);
    break;
  case 4:
    moveFinger(41);
    moveSpin(99);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton8(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(174);
    break;
  case 2:
    movePress(174);
    break;
  case 4:
    movePress(170);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button9(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(47);
    moveSpin(92);
    break;
  case 2:
    moveFinger(49);
    moveSpin(84);
    break;
  case 4:
    moveFinger(48);
    moveSpin(78);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton9(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(173);
    break;
  case 2:
    movePress(174);
    break;
  case 4:
    movePress(175);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}

/*
  This function call the move function to set the position in the desired position
 depending on the button selected
 */
void button0(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Move the finger to the position in that resolution
    moveFinger(38);
    moveSpin(101);
    break;
  case 2:
    moveFinger(34);
    moveSpin(99);
    break;
  case 4:
    moveFinger(27);
    moveSpin(99);
    break;
  }
}

/*
  Function to press the button. Call the function move, that move the finger doing
 the press action
 */
void pressButton0(){
  switch (screenResolution) {   // Checks the current resolution
  case 1:                     // Press with certain force (in a specific resolution)
    movePress(177);
    break;
  case 2:
    movePress(176);
    break;
  case 4:
    movePress(176);
    break;
  }
  delay(pressTime); // Time in seconds that the finger has to wait pressing the button, if touch pressTime = 0
  back();
}


