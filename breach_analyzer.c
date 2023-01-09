#include <stdio.h>
#include "product_config.h"
#include "breach_analyzer.h"


BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {

  int lowerLimit = limitValuesList[coolingType].lowerLimit;
  int upperLimit = limitValuesList[coolingType].upperLimit;

  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}
