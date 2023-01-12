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

TEST_CASE("Test alerter for  HI_ACTIVE_COOLING high breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;

    checkAndAlert(TO_EMAIL, batteryChar, 46, &printfunc1);

    REQUIRE(strcmp(printStr1,"To: a.b@c.com\nHi, the temperature is too high\n") == 0);

    memset(printStr1, 0, 100);

    checkAndAlert(TO_CONTROLLER, batteryChar, 46, &printfunc1);

    REQUIRE(strcmp(printStr1,"feed : 2\n") == 0);
}

TEST_CASE("Test alerter for  HI_ACTIVE_COOLING normal"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;
    memset(printStr1, 0, 100);

    checkAndAlert(TO_EMAIL, batteryChar, 30, &printfunc1);

    REQUIRE(strlen(printStr1) == 0);

    memset(printStr1, 0, 100);
    checkAndAlert(TO_CONTROLLER, batteryChar, 30, &printfunc1);
    REQUIRE(strcmp(printStr1,"feed : 0\n") == 0);

}

TEST_CASE("Test alerter for  HI_ACTIVE_COOLING low breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;

    checkAndAlert(TO_EMAIL, batteryChar, -1, &printfunc1);

    REQUIRE(strcmp(printStr1,"To: a.b@c.com\nHi, the temperature is too low\n") == 0);

    memset(printStr1, 0, 100);
    checkAndAlert(TO_CONTROLLER, batteryChar, -1, &printfunc1);
    REQUIRE(strcmp(printStr1,"feed : 1\n") == 0);
}

TEST_CASE("Test alerter for  PASSIVE_COOLING high breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;

    checkAndAlert(TO_EMAIL, batteryChar, 36, &printfunc1);

    REQUIRE(strcmp(printStr1,"To: a.b@c.com\nHi, the temperature is too high\n") == 0);

    memset(printStr1, 0, 100);
    checkAndAlert(TO_CONTROLLER, batteryChar, 36, &printfunc1);
    REQUIRE(strcmp(printStr1,"feed : 2\n") == 0);
}

TEST_CASE("Test alerter for  PASSIVE_COOLING normal"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    memset(printStr1, 0, 100);

    checkAndAlert(TO_EMAIL, batteryChar, 30, &printfunc1);

    REQUIRE(strlen(printStr1) == 0);

    memset(printStr1, 0, 100);
    checkAndAlert(TO_CONTROLLER, batteryChar, 30, &printfunc1);
    REQUIRE(strcmp(printStr1,"feed : 0\n") == 0);
}

TEST_CASE("Test alerter for  PASSIVE_COOLING low breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;

    checkAndAlert(TO_EMAIL, batteryChar, -1, &printfunc1);

    REQUIRE(strcmp(printStr1,"To: a.b@c.com\nHi, the temperature is too low\n") == 0);

    memset(printStr1, 0, 100);
    checkAndAlert(TO_CONTROLLER, batteryChar, -1, &printfunc1);
    REQUIRE(strcmp(printStr1,"feed : 1\n") == 0);
}

TEST_CASE("Test alerter for  MED_ACTIVE_COOLING high breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;

    checkAndAlert(TO_EMAIL, batteryChar, 41, &printfunc1);

    REQUIRE(strcmp(printStr1,"To: a.b@c.com\nHi, the temperature is too high\n") == 0);

    memset(printStr1, 0, 100);
    checkAndAlert(TO_CONTROLLER, batteryChar, 41, &printfunc1);
    REQUIRE(strcmp(printStr1,"feed : 2\n") == 0);
}

TEST_CASE("Test alerter for  MED_ACTIVE_COOLING normal"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;
    memset(printStr1, 0, 100);

    checkAndAlert(TO_EMAIL, batteryChar, 30, &printfunc1);

    REQUIRE(strlen(printStr1) == 0);

    memset(printStr1, 0, 100);
    checkAndAlert(TO_CONTROLLER, batteryChar, 30, &printfunc1);
    REQUIRE(strcmp(printStr1,"feed : 0\n") == 0);
}

TEST_CASE("Test alerter for  MED_ACTIVE_COOLING low breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;

    checkAndAlert(TO_EMAIL, batteryChar, -1, &printfunc1);

    REQUIRE(strcmp(printStr1,"To: a.b@c.com\nHi, the temperature is too low\n") == 0);

    memset(printStr1, 0, 100);
    checkAndAlert(TO_CONTROLLER, batteryChar, -1, &printfunc1);
    REQUIRE(strcmp(printStr1,"feed : 1\n") == 0);
}
