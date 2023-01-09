#include <stdio.h>
#include "product_config.h"
#include "breach_analyzer.h"
#include "send_alert.h"
#include "typewise-alert.h"

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC, void (*alertMessage)(char*))
{

    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

    alertTypeList[alertTarget](breachType, alertMessage);

}
