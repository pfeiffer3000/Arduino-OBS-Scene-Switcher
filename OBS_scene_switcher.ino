// Sends commands to a computer (OBS) with a 4x4 membrane keypad as a native HID

#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

// replace these sixteen values with your own key codes
// https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
char keys[ROWS][COLS] = {
    {KEY_F13, KEY_F14, KEY_F15, KEY_F8},
    {KEY_F16, KEY_F17, KEY_F18, KEY_F9},
    {KEY_F19, KEY_F20, KEY_F21, KEY_F10},
    {KEY_F22, KEY_F23, KEY_F24, KEY_F12}
};

// there are 8 pinouts from the membrane pad. 
// They represent the four rows and four columns that need to be connected to the Beetle
byte rowPins[ROWS] = {A0, A1, 15, 16};  // Row pins
byte colPins[COLS] = {14, 11, 3, 9};    // Column pins

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
    Keyboard.begin();
}

void loop(){
    char key = keypad.getKey();
    if (key){
        Keyboard.print(key);
    }
}