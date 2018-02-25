# Keypads
This is a repository of matrix keypads, along with maps and methods of using and mapping them. This was started around the LXE 2280 keypad when I was trying to retrofit one with a Raspberry Pi Zero W. The code is in Arduino C.
## IJScanner
The IJScanner is used to determine the keymap of a given matrix keypad. In this case, you connect the pins of the keypad to the digital and analog pins of an Arduino, then hold down each key, and record which key matches which pair. A sample keymap generated in this fashion can be seen in the .xlsx file for the LXE 2280.
