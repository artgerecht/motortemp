
/*
 * Oilthermistor.h - Library for reading oilthermistor temperature
 * Version: 0.2
 * Created by artgerecht, February 2017
 * 
 * Links:
 *    Thermistor:
 *      (https://www.conrad.de/de/temperatursensor-tt-electronics-ab-typ-94099-40-bis-150-c-188103.html)
 *    Code inspiration:
 *      (https://learn.adafruit.com/thermistor/using-a-thermistor)
 *      
 *      TODO:
 *      - optional constructor with thermistorPin initialisation 
 *      - optional constructor with resistor initialisation 
 *      - getter for resistance
 *      - serial prints
 * 
 */
 
#ifndef OILTHERMISTOR_H
#define OILTHERMISTOR_H


#define THERMISTORPIN A1    // analog pin of the connected thermistor
#define BUFFER 10           // how many samples to take and average
                            // more samples takes longer but is more 'smooth'
#define FIXEDRESISTOR 5100  // ohms of the fixed resistor 

// coefficients for Steinhart–Hart equation
#define A  0.00147703
#define B  0.000234533
#define C  5.06371e-07
#define D  7.91978e-08


#include <Arduino.h>

class Oilthermistor 
{
  public:
    // Constructor
    Oilthermistor ();
    float getTemp();    // convert the resistance to temperature

  private:
    uint8_t i;        // loop iterator
    float average;    
    float steinhart;
    int samples[BUFFER];
    
}; 

#endif
