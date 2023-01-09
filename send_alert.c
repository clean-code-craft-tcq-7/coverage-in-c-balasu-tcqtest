#include <stdio.h>
#include "product_config.h"
#include "alert_messages.h"
#include "send_alert.h"

void sendToController(BreachType breachType, void (*alertMessage)(char*)) {
  const unsigned short header = 0xfeed;
  char msgBuf[50];
  sprintf(msgBuf,"%x : %x\n", header, breachType);
  alertMessage(msgBuf);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  char msgBuf[100];
  if(breachType != NORMAL)
  {
      sprintf(msgBuf,"To: %s\n%s", recepient, emailAlertMessageInEng[breachType]);
      alertMessage(msgBuf);
  }
}

alertFuncPtr alertTypeList[MAX_ALERT_TYPE] = {
                &sendToController,
                &sendToEmail
};
