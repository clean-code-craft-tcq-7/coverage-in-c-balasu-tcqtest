#pragma once

typedef void (*alertFuncPtr)(BreachType, void (*alertMessage)(char*));

void sendToController(BreachType breachType, void (*alertMessage)(char*));
void sendToEmail(BreachType breachType, void (*alertMessage)(char*));

extern alertFuncPtr alertTypeList[MAX_ALERT_TYPE];
