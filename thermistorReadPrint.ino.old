/*
 * Title:   2k Thermistor Reading 
 * Version: 0.1
 * Author:  Ugurcan Albayrak
 * Date:    02/2017
 * 
 * Description:
 *    Thermistor reading for a motorcycle thermistor from conrad.
 *      (https://www.conrad.de/de/temperatursensor-tt-electronics-ab-typ-94099-40-bis-150-c-188103.html)
 *    Origin of the code:
 *      (https://learn.adafruit.com/thermistor/using-a-thermistor)
 * 
 */
class Oilthermistor 
{
  public:
    // Constructor
    Oilthermistor ();
    void begin();
    float getTemp();    // convert the resistance to temperature

  private:
    const int thermistorPin = 0;
    uint8_t i;        // loop iterator
    float average;    
    float steinhart;
    int numOfSamples;
    int samples[100];
    int fixedResistor;
    
}; 

// ################ CPP Begin


Oilthermistor::Oilthermistor () {            // Constructor
  // how many samples to take and average
  // more samples takes longerbut is more 'smooth'
  numOfSamples  = 100;
  
  // value of the 'other' (fixed) resistor
  fixedResistor = 5000;
}

void Oilthermistor::begin() {
  getTemp();
}


// convert the resistance to temperature
float Oilthermistor::getTemp() {                          // Calculation
  // take N samples in a row, with a slight delay
  for (i=0; i< numOfSamples; i++) {
   samples[i] = analogRead(0);
   delay(10);
  }
 
  // average all the samples out
  average = 0;
  for (i=0; i< numOfSamples; i++) {
     average += samples[i];
  }
  average /= numOfSamples;
 
  //Serial.print("Average analog reading "); 
  //Serial.println(average);
 
  // convert the value to resistance
  average = 1023 / average - 1;
  average = fixedResistor / average;
  //Serial.print("Thermistor resistance "); 
  //Serial.println(average);

  /*float A, B, C, D;
  A = 0.00147703;
  B = 0.000234533;
  C = 5.06371e-07;
  D = 7.91978e-08;
  ...
  steinhart = 1.0 / (A + B*steinhart + C*(steinhart*steinhart) + D*(steinhart*steinhart*steinhart));
  */
  
  steinhart = average;                      // (R/Ro)
  steinhart = log(steinhart);               // ln(R/Ro)
  steinhart = 1.0 / (0.00147703 + 0.000234533*steinhart + 5.06371e-07*(steinhart*steinhart) + 7.91978e-08*(steinhart*steinhart*steinhart));
  steinhart -= 273.15;                      // convert to C
  
  return steinhart;
}

// #################################### OOP END #####

// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup(void) {
  Serial.begin(9600);
  analogReference(EXTERNAL);
  lcd.begin(16, 2);
}
 
void loop(void) {   
  Oilthermistor obj1;
  lcd.print(obj1.getTemp());
  lcd.print(" *C");
  delay(1000);
  
  lcd.setCursor(0, 0);

}



