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

    LimitValue limitValues;

    limitValues = getLimitValues(coolingType);

  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

LimitValue getLimitValues(CoolingType coolingType)
{
    LimitValue retVariable;

    retVariable.lowerLimit = limitValuesList[coolingType].lowerLimit;
    retVariable.upperLimit = limitValuesList[coolingType].upperLimit;

    return retVariable;
}
