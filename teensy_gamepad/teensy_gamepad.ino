
/************************************
*         Gamepad config            *
************************************/
#include <Bounce.h>

// Joystick setup

// If you have only one analog stick, set this to 1,
// If you have 2, set this to 2,
// If you do not have any at all, set this to 0.
// In theory, 4 are possible, but this script is limited to 2.
int AnalogSticks = 2;

// Analog stick input pins, invert, and deadzone:
int deadzone = 8; // Values under 5 will return 0
int x1Pin = 8;
int y1Pin = 9;
int x2Pin = 6;
int y2Pin = 7;
int InvertX1 = 1;
int InvertY1 = 1;
int InvertX2 = 0;
int InvertY2 = 1;

// Variable declarations for analog sticks
int x1Zero, y1Zero;
int x1Value, y1Value;
int x2Zero, y2Zero;
int x2Value, y2Value;
int x1Min, x1Max;
int y1Min, y1Max;
int x2Min, x2Max;
int y2Min, y2Max;
int x1F1, x1F2;
int y1F1, y1F2;
int x2F1, x2F2;
int y2F1, y2F2;

// Hat setup

const int left    = 0;
const int up      = 1;
const int down    = 2;
const int right   = 3;


// Button Setup

Bounce slt     = Bounce(4, 10);
Bounce srt     = Bounce(5, 10);
Bounce x       = Bounce(6, 110);
Bounce y       = Bounce(7, 10);
Bounce b       = Bounce(8, 10);
Bounce a       = Bounce(9, 10);
Bounce r2      = Bounce(10, 10);
Bounce r1      = Bounce(11, 10);
Bounce l1      = Bounce(12, 10);
Bounce l2      = Bounce(28, 10);

int buttonPins[] = {
  0,1,2,3,4,5,6,7,8,9,10,11,12,28
}; 
int buttonPinCount = 14;


/************************************
*         LED config                *
************************************/

//If not using a led in the project, comment the next 2 lines
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 25, NEO_RGB + NEO_KHZ800);

//set useLed to false if not using led
int useLed   = true;
int pipower  = 29;
int lowbatt  = 30;
int charging = 26;
int charged  = 27;




/****************
* Set Led Color *
*****************/  
int setLed(int r,int g, int b, int a){
   strip.setPixelColor(0, r, g, b);
   strip.setBrightness(a);
   strip.show();
};


/****************
* Hat Functions *
*****************/
void setHat(){

  if (digitalRead(left) == LOW) {
    Joystick.hat(270);
   } else if (digitalRead(up) == LOW)  {
    Joystick.hat(0);
   } else if (digitalRead(down) == LOW)  {
    Joystick.hat(180);
  } else if (digitalRead(right) == LOW)  {
    Joystick.hat(90);
  } else {
    Joystick.hat(-1);
  }
}


/********************
* Buttons functions *
********************/
   void setButtons(){
   // Update all the buttons.  
   slt.update();
   srt.update();
   x.update();
   y.update();
   b.update();
   a.update();
   r2.update();
   r1.update();
   l1.update();
   l2.update();

  // Check each button for "falling" edge.
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (slt.fallingEdge()) {
    Joystick.button(1, 1);
  }
  if (srt.fallingEdge()) {
    Joystick.button(2, 1);
  }
  if (x.fallingEdge()) {
    Joystick.button(3, 1);
  }
  if (y.fallingEdge()) {
    Joystick.button(4, 1);
  }
  if (b.fallingEdge()) {
    Joystick.button(5, 1);
  }
  if (a.fallingEdge()) {
    Joystick.button(6, 1);
  }
  if (r2.fallingEdge()) {
    Joystick.button(7, 1);
  }
  if (r1.fallingEdge()) {
    Joystick.button(8, 1);
  }
  if (l1.fallingEdge()) {
    Joystick.button(9, 1);
  }
  if (l2.fallingEdge()) {
    Joystick.button(10, 1);
  }

  // Check each button for "rising" edge
  // Update the Joystick buttons only upon changes.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (slt.risingEdge()) {
    Joystick.button(1, 0);
  }
  if (srt.risingEdge()) {
    Joystick.button(2, 0);
  }
  if (x.risingEdge()) {
    Joystick.button(3, 0);
  }
  if (y.risingEdge()) {
    Joystick.button(4, 0);
  }
  if (b.risingEdge()) {
    Joystick.button(5, 0);
  }
  if (a.risingEdge()) {
    Joystick.button(6, 0);
  }
  if (r2.risingEdge()) {
    Joystick.button(7, 0);
  }
  if (r1.risingEdge()) {
    Joystick.button(8, 0);
  }
  if (l1.risingEdge()) {
    Joystick.button(9, 0);
  }
  if (l2.risingEdge()) {
    Joystick.button(10, 0);
  }
}

/*********************
* Joystick functions *
**********************/
void setJoystick(){
  // Read analog sticks and respect the deadzone value
  x1Value = analogRead(x1Pin) - x1Zero;
  y1Value = analogRead(y1Pin) - y1Zero;
  x2Value = analogRead(x2Pin) - x2Zero;
  y2Value = analogRead(y2Pin) - y2Zero;

  if(abs(x1Value) < deadzone) {
    x1Value = 0;
  }
  if(abs(y1Value) < deadzone) {
    y1Value = 0;
  }
  if(abs(x2Value) < deadzone) {
    x2Value = 0;
  }
  if(abs(y2Value) < deadzone) {
    y2Value = 0;
  }

  // Autocalibration of analog sticks (by Helder + wermy)
  if (x1Value > 0 && x1Value > x1Max) {
    x1Max = x1Value;
  } else if (x1Value < 0 && x1Value < x1Min) {
    x1Min = x1Value;
  }

  if (y1Value > 0 && y1Value > y1Max) {
    y1Max = y1Value;
  } else if (y1Value < 0 && y1Value < y1Min) {
    y1Min = y1Value;
  }

  float x1sMax = abs(x1Max);
  if (x1Value < 0) {
    x1sMax = abs(x1Min);
  }

  float y1sMax = abs(y1Max);
  if (y1Value < 0) {
    y1sMax = abs(y1Min);
  }
  
  if (x2Value > 0 && x2Value > x2Max) {
    x2Max = x2Value;
  } else if (x2Value < 0 && x2Value < x2Min) {
    x2Min = x2Value;
  }

  if (y2Value > 0 && y2Value > y2Max) {
    y2Max = y2Value;
  } else if (y2Value < 0 && y2Value < y2Min) {
    y2Min = y2Value;
  }

  float x2sMax = abs(x2Max);
  if (x2Value < 0) {
    x2sMax = abs(x2Min);
  }

  float y2sMax = abs(y2Max);
  if (y2Value < 0) {
    y2sMax = abs(y2Min);
  }
  int16_t x1Final = (((float)x1Value / x1sMax)*127);
  int16_t y1Final = (((float)y1Value / y1sMax)*127);
  int16_t x2Final = (((float)x2Value / x2sMax)*127);
  int16_t y2Final = (((float)y2Value / y2sMax)*127);

  // Check if Axes need to be inverted, and if yes, do so
  if (InvertX1 == 0) {
    x1F1 = 127;
    x1F2 = -127;
  }
  else {
    x1F1 = -127;
    x1F2 = 127;
  }
  if (InvertY1 == 0) {
    y1F1 = 127;
    y1F2 = -127;
  }
  else {
    y1F1 = -127;
    y1F2 = 127;
  }
  if (InvertX2 == 0) {
    x2F1 = 127;
    x2F2 = -127;
  }
  else {
    x2F1 = -127;
    x2F2 = 127;
  }
  if (InvertY2 == 0) {
    y2F1 = 127;
    y2F2 = -127;
  }
  else {
    y2F1 = -127;
    y2F2 = 127;
  }
  
  // Check how many analog sticks have been specified (0, 1, 2)
  // and disable (center) any that aren't used.
  if (AnalogSticks != 1 && AnalogSticks != 2) {
    x1Final = 0;
    y1Final = 0;
    x2Final = 0;
    y2Final = 0;
  }
  if (AnalogSticks == 1) {
    x1Final = 0;
    y1Final = 0;
  }
  
  // Parse autocalibrated analog stick values
  Joystick.X(map(x1Final, x1F1, x1F2, 0, 1023));
  Joystick.Y(map(y1Final, y1F1, y1F2, 0, 1023));
  Joystick.Z(map(x2Final, x2F1, x2F2, 0, 1023));
  Joystick.Zrotate(map(y2Final, y2F1, y2F2, 0, 1023));
}


// Main setup


void setup() { 

  /************************************
  *         Gamepad setup             *
  ************************************/

  //  Take manual control of joystick send function
  Joystick.useManualSend(true);
  
  // initialize all the readings to 0:
  // Measure 'neutral' position for analog sticks
  x1Zero = analogRead(x1Pin);
  y1Zero = analogRead(y1Pin);
  x2Zero = analogRead(x2Pin);
  y2Zero = analogRead(y2Pin);
  
  //  init all buttons as pullups
  for (int button = 0; button < buttonPinCount; button++) {
    pinMode(buttonPins[button], INPUT_PULLUP);
  }

  
  /************************************
  *         LED setup                 *
  ************************************/
  
  pinMode(pipower, INPUT_PULLUP);
  pinMode(lowbatt, INPUT_PULLUP);
  pinMode(charging, INPUT_PULLUP);
  pinMode(charged, INPUT_PULLUP);
  strip.begin();
  setLed(0,0,0,0);
  
};



void loop() {
  if (useLed == true){
    if (digitalRead(pipower) == LOW){
          setLed(255,120,0,8);

        if (digitalRead(lowbatt) == LOW){
          setLed(255,50,50,8);
        }

//        if (digitalRead(charging)){
//          // TODO multitasked charging animation
//          setLed(255,255,175,8);
//        }
//
//        if (digitalRead(charged)){
//          setLed(80,255,100,8);
//        }
        setHat();
        setButtons();
        setJoystick();  
        Joystick.send_now();
        delay(10);
    }else{
      
      // if (digitalRead(charging)){
      //    // TODO charging animation
      //    setLed(255,255,175,8);
      // }
//          
//       if (digitalRead(charged)){
//          setLed(80,255,100,8);
//       }
    }
  } else if(useLed == false) {
        setHat();
        setButtons();
        setJoystick();  
        Joystick.send_now();
        delay(10);
  }
    
}

