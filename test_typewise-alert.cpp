#include <stdio.h>
#include <string.h>
#include "test/catch.hpp"
#include "product_config.h"
#include "typewise-alert.h"

char printStr1[100];

void printfunc1(char* buff)
{
    strcpy(printStr1, buff);
}

TEST_CASE("Alert via Email HI_ACTIVE_COOLING high breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;

    checkAndAlert(TO_EMAIL, batteryChar, 46, &printfunc1);

    REQUIRE(strcmp(printStr1,"To: a.b@c.com\nHi, the temperature is too high\n") == 0);
}
