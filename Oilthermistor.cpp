
/*
 * Oilthermistor.h - Library for reading oilthermistor temperature
 * Version: 0.2
 * Created by Ugurcan Albayrak, February 2017
 * 
 * Copyright (C): Ugurcan Albayrak
 *
 */
 
  
#include "Oilthermistor.h"


Oilthermistor::Oilthermistor ()                   // Constructor
{                       
  
}

float Oilthermistor::getTemp()                  // calculate and return temperature
{                          
  // take N samples in a row, with a slight delay
  average = 0;
  for (i=0; i< BUFFER; i++)
  {
   samples[i] = analogRead(THERMISTORPIN);
   average += samples[i];
   delay(10);
  }
 
  // average all the samples out
  average /= BUFFER;
 
  // convert the value to resistance
  average = 1023 / average - 1;
  average = FIXEDRESISTOR / average;

  // convert resistance to temperature in celsius
  /*
   * A = 0.00147703
   * B = 0.000234533
   * C = 5.06371e-07
   * D = 7.91978e-08
   * ...
   * steinhart = 1.0 / (A +B*steinhart + C*(steinhart^2) + D*(steinhart^3));
   */
  
  steinhart = average;                      // (R/Ro)
  steinhart = log(steinhart);               // ln(R/Ro)
  steinhart = 1.0 / (A + B*steinhart + C*(steinhart*steinhart) + D*(steinhart*steinhart*steinhart));
  steinhart -= 273.15;                      // convert to C
  
  return steinhart;
}

