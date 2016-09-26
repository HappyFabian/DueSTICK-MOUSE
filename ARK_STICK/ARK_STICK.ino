#include <Mouse.h>
#include <Joystick.h>


//Pin List
int modePIN = 12;

int upPIN = 5;
int downPIN = 4;
int leftPIN = 3;
int rightPIN = 2;
int selectPIN = 8;
int startPIN = 9;
int Button0PIN = 22;
int Button1PIN = 24;
int Button2PIN = 26;
int Button3PIN = 28;
int Button4PIN = 30;
int Button5PIN = 32;
int Button6PIN = 34;
int Button7PIN = 36;


void setup() {
  // put your setup code here, to run once:]
  //mode Pin
  pinMode(modePIN, INPUT_PULLUP); 
  pinMode(upPIN, INPUT_PULLUP);
  pinMode(downPIN, INPUT_PULLUP);
  pinMode(leftPIN, INPUT_PULLUP);
  pinMode(rightPIN, INPUT_PULLUP);
  pinMode(startPIN, INPUT_PULLUP);
  pinMode(selectPIN, INPUT_PULLUP);
  pinMode(Button0PIN,INPUT_PULLUP);
  pinMode(Button1PIN,INPUT_PULLUP);
  pinMode(Button2PIN,INPUT_PULLUP);
  pinMode(Button3PIN,INPUT_PULLUP);
  pinMode(Button4PIN,INPUT_PULLUP);
  pinMode(Button5PIN,INPUT_PULLUP);
  pinMode(Button6PIN,INPUT_PULLUP);
  pinMode(Button7PIN,INPUT_PULLUP);
  Mouse.begin();
  Joystick.begin();
}

int ModeClickValue = 0, lastModeClickValue = 0;

int UP = 0, RIGHT = 0, LEFT = 0, DOWN = 0;
int lastUP = 0, lastRIGHT = 0, lastLEFT = 0, lastDOWN = 0;

//Generally Start and Select, 
int START = 0, lastSTART = 0, counterSTART = 0;
int SELECT = 0, lastSELECT = 0, counterSELECT = 0;

//Generally Buttons
int Button0 = 0;
int Button1 = 0;
int Button2 = 0;
int Button3 = 0;
int Button4 = 0;
int Button5 = 0;
int Button6 = 0;
int Button7 = 0;

//Mode 0 = Standby, 1= Joystick,  2 = Keyboard,3 = Mouse
int mode = 0;

void checkModeState()
{
  if(ModeClickValue == 0 && lastModeClickValue != ModeClickValue)
  {
    switch(mode)
    {
      case 0:
        {  mode = 1; } 
        break;
      case 1:
        {  mode = 2; } 
        break;
      case 2:
        {  mode = 0; }
        break;
    }
    lastModeClickValue = ModeClickValue;
  }
  else
  {
    lastModeClickValue = ModeClickValue;  
  }
}

void checkJoystickInterpretation()
{
  if(START == 0){Joystick.setButton(0,1);}else{Joystick.setButton(0,0);}
  if(SELECT == 0){Joystick.setButton(1,1);}else{Joystick.setButton(1,0);}
  if(Button0 == 0){Joystick.setButton(2,1);}else{Joystick.setButton(2,0);}
  if(Button1 == 0){Joystick.setButton(3,1);}else{Joystick.setButton(3,0);}
  if(Button2 == 0){Joystick.setButton(4,1);}else{Joystick.setButton(4,0);}
  if(Button3 == 0){Joystick.setButton(5,1);}else{Joystick.setButton(5,0);}
  if(Button4 == 0){Joystick.setButton(6,1);}else{Joystick.setButton(6,0);}
  if(Button5 == 0){Joystick.setButton(7,1);}else{Joystick.setButton(7,0);}
  if(Button6 == 0){Joystick.setButton(8,1);}else{Joystick.setButton(8,0);}
  if(Button7 == 0){Joystick.setButton(9,1);}else{Joystick.setButton(9,0);}
  
  if(DOWN == 0){ Joystick.setYAxis(-127); }
  if(UP == 0){ Joystick.setYAxis(127); }
  if(UP != 0 && DOWN != 0){ Joystick.setYAxis(0); }

  if(LEFT == 0){Joystick.setXAxis(-127);}
  if(RIGHT == 0){Joystick.setXAxis(127);}
  if(LEFT != 0 && RIGHT != 0){Joystick.setXAxis(0);}
}

void checkMouseInterpretation()
{
  int xDirection = (LEFT - RIGHT)*10;
  int yDirection = (DOWN - UP)*10;
  if(Button0 == 0 && Button1 == 1){Mouse.click(MOUSE_LEFT);}else{}
  if(Button0 == 1 && Button1 == 0){Mouse.click(MOUSE_RIGHT);}else{}

  if((xDirection != 0) || (yDirection != 0))
  {
    Mouse.move(xDirection,yDirection,0);   
  }
  delay(50);  
}

void updatePinReadValues()
{
  ModeClickValue = digitalRead(modePIN);
  
  START = digitalRead(startPIN);
  SELECT = digitalRead(selectPIN);
  Button0 = digitalRead(Button0PIN);
  Button1 = digitalRead(Button1PIN);
  Button2 = digitalRead(Button2PIN);
  Button3 = digitalRead(Button3PIN);
  Button4 = digitalRead(Button4PIN);
  Button5 = digitalRead(Button5PIN);
  Button6 = digitalRead(Button6PIN);
  Button7 = digitalRead(Button7PIN);

  
  UP = digitalRead(upPIN);
  DOWN = digitalRead(downPIN);
  LEFT = digitalRead(leftPIN);
  RIGHT = digitalRead(rightPIN);
}

void modeInputInterpretation()
{
  switch(mode)
  {
    case 0: {} break;
    case 1: {checkJoystickInterpretation();} break;
    case 2:{checkMouseInterpretation();} break;
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

  updatePinReadValues();
  checkModeState();
  modeInputInterpretation();


  delay(25);
}
