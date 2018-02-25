/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
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

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.print(key);
  }
}
