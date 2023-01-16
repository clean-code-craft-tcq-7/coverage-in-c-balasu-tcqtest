#include <stdio.h>
#include "product_config.h"
#include "alert_messages.h"
#include "send_alert.h"

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;

  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {

  char msgBuf[100];
  if(breachType != NORMAL)
  {
      sprintf(msgBuf,"To: %s\n%s", recepient, emailAlertMessageInEng[breachType]);
      printf("%s",msgBuf);
  }
}

alertFuncPtr alertTypeList[MAX_ALERT_TYPE] = {
                &sendToController,
                &sendToEmail
};
