#pragma once

typedef void (*alertFuncPtr)(BreachType);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);

extern alertFuncPtr alertTypeList[MAX_ALERT_TYPE];
