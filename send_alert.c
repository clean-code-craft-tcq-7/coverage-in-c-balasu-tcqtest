#include <stdio.h>
#include "product_config.h"
#include "alert_messages.h"
#include "send_alert.h"

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";

  if(breachType != NORMAL)
  {
      printf("To: %s\n", recepient);
      printf(emailAlertMessageInEng[breachType]);
  }
}

alertFuncPtr alertTypeList[MAX_ALERT_TYPE] = {
                &sendToController,
                &sendToEmail
};
