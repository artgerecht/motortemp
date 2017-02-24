// include the library code:
#include "Oilthermistor.h"
#include <LCD5110_Graph.h>

// initialize the library with the numbers of the interface pins
#define RST 12
#define CE 11
#define DC 10 
#define DIN 9
#define CLK 8
 
LCD5110 lcd(CLK, DIN, DC, RST, CE);  
extern unsigned char SmallFont[];
extern unsigned char BigNumbers[];

Oilthermistor obj1;


// SETUP
void setup(void) {
  lcd.InitLCD(50);
  analogReference(EXTERNAL);
  // Intro
  lcd.clrScr();
  lcd.setFont(SmallFont);
  lcd.print(F("GUTE FAHRT  =)"), CENTER, 18);
  lcd.update(); 
  delay(2000);
}


// LOOP
void loop(void) {
  lcd.clrScr();                                 // clear screen
  lcd.setFont(SmallFont);                       // set font to "SmallFont"
  lcd.print(F("Motor"), CENTER, 0);             // write string to buffer
  lcd.drawLine(0, 9, 84, 9);                    // write line to buffer
  lcd.setFont(BigNumbers);                      // set font to "BigNumbers"
  lcd.printNumF(obj1.getTemp(),1,CENTER,16);    // write float value to buffer
  lcd.update();                                 // load buffer to display
  
  delay(1500);
}



