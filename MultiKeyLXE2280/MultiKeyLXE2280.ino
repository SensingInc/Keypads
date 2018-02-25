/* @file MultiKey.ino
|| @version 1.0
|| @author Mark Stanley
|| @contact mstanley@technologist.com
||
|| @description
|| | The latest version, 3.0, of the keypad library supports up to 10
|| | active keys all being pressed at the same time. This sketch is an
|| | example of how you can get multiple key presses from a keypad or
|| | keyboard.
|| #
*/

#include <Keypad.h>
const byte ROWS = 8; //eight rows
const byte COLS = 8; //eight columns
char keys[ROWS][COLS] = {
{0x07,0x0e,0x10,0x12,0x14,0x16,0x18,' '},
{'0',0x0b,'w','r','y','i','p','8'},
{'9',0x0c,'q','e','t','u','o','7'},
{' ',0x08,0x0f,0x11,0x13,0x15,0x17,'\n'},
{'3',0xe2,' ','x','v','n',0x1c,'1'},
{'\t',' ','s','f','h','k',0x1c,'5'},
{'6',0xe0,'a','d','g','j','l','4'},
{'.',0xe1,'z','c','b','m',' ','2'}
};
byte rowPins[ROWS] = {9, 10, 11, 12, A4, A0, A1, A2}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {2, 3, 4, 5, 6, 7, 8, A3}; //connect to the column pinouts of the kpd

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;


void setup() {
    Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    msg = "";
}


void loop() {
    loopCount++;
    if ( (millis()-startTime)>5000 ) {
//        Serial.print("Average loops per second = ");
//        Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
//        {
//            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
//            {
//                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
//                    case PRESSED:
//                    msg = " PRESSED.";
//                break;
//               //     case HOLD:
////                    msg = " HOLD.";
////                break;
////                    case RELEASED:
////                    msg = " RELEASED.";
////                break;
////                    case IDLE:
////                    msg = " IDLE.";
//                }
               // Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
               // Serial.println(msg);
           // }
      //  }
    }
}  // End loop
