// Created by Luis Saborio H.
/*
  This is an arm used to control an application developed
  for mobile devices, such as smartphones and tablets, this
  arm has to support 3 different screen resolutions and 
  press buttons from 0 to 9 in an specific order
*/
#include <Servo.h>

Servo servoPress, servoFinger, servoSpin;

//int posX = 90, posY = 0, spin= 90;

int btn = 0, screenResolution = 0, pressTime = 0, force = 5, downspeed = 20, pressBtn = 0;

void setup() {  // This function is used to set de configuration of the arduino
  servoPress.attach(6);
  servoFinger.attach(7);
  servoSpin.attach(8);
  back();
  Serial.begin(9600);
  delay(1000);  // Wait 1 second to start the execution
}

void loop() {

//***Manual Calibration**************************************************************
//  if (Serial.available() > 0)
//  {
//    back();
//    
//    posX = Serial.parseInt();
//    posY = Serial.parseInt();
//    spin = Serial.parseInt();
//    pressTime = 2000;
//    
//    Serial.print(posX);
//    Serial.print(",");
//    Serial.print(posY);
//    Serial.print(",");
//    Serial.println(spin);
//    move2(posY);
//    move3(spin);
//    move1(posX);
//
//    delay(pressTime);
//    back();
//  }
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

void back(){
  if(servoPress.read() < 90){
    for (int x = servoPress.read(); x <= 90; x += 1) {  // goes from actual position to 90 degrees
      servoPress.write(x);                              // tell servo to go to position in variable 'x'
      delay(15);                                        // waits 15ms for the servo to reach the position
    }
  } else {
    for (int x = servoPress.read(); x >= 90; x -= 1) {  // goes from actual position to 90 degrees
      servoPress.write(x);                              // tell servo to go to position in variable 'x'
      delay(15);                                        // waits 15ms for the servo to reach the position
    }
  }

  for (int x = servoFinger.read(); x >= 0; x -= 1) {    // goes from actual position to 0 degrees
    servoFinger.write(x);                               // tell servo to go to position in variable 'x'
    delay(15);                                          // waits 15ms for the servo to reach the position
  }

  if(servoSpin.read() < 90){
    for (int x = servoSpin.read(); x <= 90; x += 1) {   // goes from actual position to 90 degrees
      servoSpin.write(x);                               // tell servo to go to position in variable 'x'
      delay(15);                                        // waits 15ms for the servo to reach the position
    }
  } else {
    for (int x = servoSpin.read(); x >= 90; x -= 1) {   // goes from actual position to 90 degrees
      servoSpin.write(x);                               // tell servo to go to position in variable 'x'
      delay(15);                                        // waits 15ms for the servo to reach the position
    }
  }
  
}

void move1(int pos){
  if(servoPress.read() != pos){              // check if the servo is already in the position
    if(pos > 90){                            // check in which direction it should move
      for (int x = 90; x <= pos; x += 1) {   // goes from 90 degrees to a specific position
        servoPress.write(x);                 // tell servo to go to position in variable 'x'
        delay(downspeed);                    // waits an specific time (speed) for the servo to reach the position
      }
    } else {
      for (int x = 90; x >= pos; x -= 1) {   // goes from 90 degrees to a specific position
        servoPress.write(x);                 // tell servo to go to position in variable 'x'
        delay(downspeed);                    // waits an specific time (speed) for the servo to reach the position
      }
    }
  }
}

void move2(int pos){
  if(servoFinger.read() != pos){             // check if the servo is already in the position
    for (int x = 0; x <= pos; x += 1) {      // goes from 0 degrees to a specific position
      servoFinger.write(x);                  // tell servo to go to position in variable 'x'
      delay(15);                             // waits 15ms for the servo to reach the position
    }
    delay(200);
  }
}

void move3(int pos){
  if(servoSpin.read() != pos){               // check if the servo is already in the position
    if(pos > 90){                            // check in which direction it should move
      for (int x = 90; x <= pos; x += 1) {   // goes from 90 degrees to a specific position
        servoSpin.write(x);                  // tell servo to go to position in variable 'x'
        delay(15);                           // waits 15ms for the servo to reach the position
      }
    } else {
      for (int x = 90; x >= pos; x -= 1) {   // goes from 90 degrees to a specific position
        servoSpin.write(x);                  // tell servo to go to position in variable 'x'
        delay(15);                           // waits 15ms for the servo to reach the position
      }
    }
    delay(200);
  }
}

void button1(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(9);
      move3(103);
      break;
    case 2:
      move2(9);
      move3(103);
      break;
    case 3:
      move2(9);
      move3(103);
      break;
  }
}

void pressButton1(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(154 + force);
      break;
    case 2:
      move1(154 + force);
      break;
    case 3:
      move1(154 + force);
      break;
  }
  delay(pressTime);
  back();
}

void button2(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(9);
      move3(94);
      break;
    case 2:
      move2(9);
      move3(94);
      break;
    case 3:
      move2(9);
      move3(94);
      break;
  }
}

void pressButton2(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(153 + force);
      break;
    case 2:
      move1(153 + force);
      break;
    case 3:
      move1(153 + force);
      break;
  }
  delay(pressTime);
  back();
}

void button3(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(9);
      move3(86);
      break;
    case 2:
      move2(9);
      move3(86);
      break;
    case 3:
      move2(9);
      move3(86);
      break;
  }
}

void pressButton3(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(156 + force);
      break;
    case 2:
      move1(156 + force);
      break;
    case 3:
      move1(156 + force);
      break;
  }
  delay(pressTime);
  back();
}

void button4(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(18);
      move3(102);
      break;
    case 2:
      move2(18);
      move3(102);
      break;
    case 3:
      move2(18);
      move3(102);
      break;
  }
}

void pressButton4(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(154 + force);
      break;
    case 2:
      move1(154 + force);
      break;
    case 3:
      move1(154 + force);
      break;
  }
  delay(pressTime);
  back();
}

void button5(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(18);
      move3(94);
      break;
    case 2:
      move2(18);
      move3(94);
      break;
    case 3:
      move2(18);
      move3(94);
      break;
  }
}

void pressButton5(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(154 + force);
      break;
    case 2:
      move1(154 + force);
      break;
    case 3:
      move1(154 + force);
      break;
  }
  delay(pressTime);
  back();
}

void button6(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(19);
      move3(86);
      break;
    case 2:
      move2(19);
      move3(86);
      break;
    case 3:
      move2(19);
      move3(86);
      break;
  }
}

void pressButton6(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(153 + force);
      break;
    case 2:
      move1(153 + force);
      break;
    case 3:
      move1(153 + force);
      break;
  }
  delay(pressTime);
  back();
}

void button7(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(29);
      move3(102);
      break;
    case 2:
      move2(29);
      move3(102);
      break;
    case 3:
      move2(29);
      move3(102);
      break;
  }
}

void pressButton7(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(155 + force);
      break;
    case 2:
      move1(155 + force);
      break;
    case 3:
      move1(155 + force);
      break;
  }
  delay(pressTime);
  back();
}

void button8(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(29);
      move3(94);
      break;
    case 2:
      move2(29);
      move3(94);
      break;
    case 3:
      move2(29);
      move3(94);
      break;
  }
}

void pressButton8(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(152 + force);
      break;
    case 2:
      move1(152 + force);
      break;
    case 3:
      move1(152 + force);
      break;
  }
  delay(pressTime);
  back();
}

void button9(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(29);
      move3(88);
      break;
    case 2:
      move2(29);
      move3(88);
      break;
    case 3:
      move2(29);
      move3(88);
      break;
  }
}

void pressButton9(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(154 + force);
      break;
    case 2:
      move1(154 + force);
      break;
    case 3:
      move1(154 + force);
      break;
  }
  delay(pressTime);
  back();
}

void button0(){                 // Function to put the finger in position to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Move the finger to the position in that resolution
      move2(0);
      move3(100);
      break;
    case 2:
      move2(0);
      move3(100);
      break;
    case 3:
      move2(0);
      move3(100);
      break;
  }
}

void pressButton0(){            // Function to press the button
  switch (screenResolution) {   // Checks the current resolution
    case 1:                     // Press with certain force (in a specific resolution)
      move1(158 + force);
      break;
    case 2:
      move1(158 + force);
      break;
    case 3:
      move1(158 + force);
      break;
  }
  delay(pressTime);
  back();
}

