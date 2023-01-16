#include <stdio.h>
#include <string.h>
#include "test/catch.hpp"
#include "product_config.h"
#include "typewise-alert.h"
#include "send_alert.h"

int test_cntrlrAlerted = 0;
BreachType test_cntrlrBrchType;
int test_emailAlerted = 0;
BreachType test_emailBrchType;

void cntrlrAlertMock(BreachType type)
{
    test_cntrlrAlerted = 1;
    test_cntrlrBrchType = type;
}

void emailAlertMock(BreachType type)
{
    test_emailAlerted = 1;
    test_emailBrchType = type;
}


TEST_CASE("Test alerter for  HI_ACTIVE_COOLING high breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;
    test_cntrlrAlerted = 0;
    test_emailAlerted = 0;
    alertTypeList[TO_CONTROLLER] = &cntrlrAlertMock;
    alertTypeList[TO_EMAIL] = &emailAlertMock;

    checkAndAlert(TO_CONTROLLER, batteryChar, 46);
    REQUIRE(test_cntrlrAlerted == 1);
    REQUIRE(test_cntrlrBrchType == TOO_HIGH);

    checkAndAlert(TO_EMAIL, batteryChar, 46);
    REQUIRE(test_emailAlerted == 1);
    REQUIRE(test_emailBrchType == TOO_HIGH);
}

TEST_CASE("Test alerter for  HI_ACTIVE_COOLING normal"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;
    test_cntrlrAlerted = 0;
    test_emailAlerted = 0;
    alertTypeList[TO_CONTROLLER] = &cntrlrAlertMock;
    alertTypeList[TO_EMAIL] = &emailAlertMock;

    checkAndAlert(TO_EMAIL, batteryChar, 30);
    REQUIRE(test_emailAlerted == 1);
    REQUIRE(test_emailBrchType == NORMAL);

    checkAndAlert(TO_CONTROLLER, batteryChar, 30);
    REQUIRE(test_cntrlrAlerted == 1);
    REQUIRE(test_cntrlrBrchType == NORMAL);

}

TEST_CASE("Test alerter for  HI_ACTIVE_COOLING low breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = HI_ACTIVE_COOLING;
    test_cntrlrAlerted = 0;
    test_emailAlerted = 0;
    alertTypeList[TO_CONTROLLER] = &cntrlrAlertMock;
    alertTypeList[TO_EMAIL] = &emailAlertMock;

    checkAndAlert(TO_EMAIL, batteryChar, -1);
    REQUIRE(test_emailAlerted == 1);
    REQUIRE(test_emailBrchType == TOO_LOW);

    checkAndAlert(TO_CONTROLLER, batteryChar, -1);
    REQUIRE(test_cntrlrAlerted == 1);
    REQUIRE(test_cntrlrBrchType == TOO_LOW);
}

TEST_CASE("Test alerter for  PASSIVE_COOLING high breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    test_cntrlrAlerted = 0;
    test_emailAlerted = 0;
    alertTypeList[TO_CONTROLLER] = &cntrlrAlertMock;
    alertTypeList[TO_EMAIL] = &emailAlertMock;

    checkAndAlert(TO_EMAIL, batteryChar, 36);
    REQUIRE(test_emailAlerted == 1);
    REQUIRE(test_emailBrchType == TOO_HIGH);

    checkAndAlert(TO_CONTROLLER, batteryChar, 36);
    REQUIRE(test_cntrlrAlerted == 1);
    REQUIRE(test_cntrlrBrchType == TOO_HIGH);
}

TEST_CASE("Test alerter for  PASSIVE_COOLING normal"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    test_cntrlrAlerted = 0;
    test_emailAlerted = 0;
    alertTypeList[TO_CONTROLLER] = &cntrlrAlertMock;
    alertTypeList[TO_EMAIL] = &emailAlertMock;

    checkAndAlert(TO_EMAIL, batteryChar, 30);
    REQUIRE(test_emailAlerted == 1);
    REQUIRE(test_emailBrchType == NORMAL);

    checkAndAlert(TO_CONTROLLER, batteryChar, 30);
    REQUIRE(test_cntrlrAlerted == 1);
    REQUIRE(test_cntrlrBrchType == NORMAL);
}

TEST_CASE("Test alerter for  PASSIVE_COOLING low breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = PASSIVE_COOLING;
    test_cntrlrAlerted = 0;
    test_emailAlerted = 0;
    alertTypeList[TO_CONTROLLER] = &cntrlrAlertMock;
    alertTypeList[TO_EMAIL] = &emailAlertMock;

    checkAndAlert(TO_EMAIL, batteryChar, -1);
    REQUIRE(test_emailAlerted == 1);
    REQUIRE(test_emailBrchType == TOO_LOW);

    checkAndAlert(TO_CONTROLLER, batteryChar, -1);
    REQUIRE(test_cntrlrAlerted == 1);
    REQUIRE(test_cntrlrBrchType == TOO_LOW);
}

TEST_CASE("Test alerter for  MED_ACTIVE_COOLING high breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;
    test_cntrlrAlerted = 0;
    test_emailAlerted = 0;
    alertTypeList[TO_CONTROLLER] = &cntrlrAlertMock;
    alertTypeList[TO_EMAIL] = &emailAlertMock;

    checkAndAlert(TO_EMAIL, batteryChar, 41);
    REQUIRE(test_emailAlerted == 1);
    REQUIRE(test_emailBrchType == TOO_HIGH);

    checkAndAlert(TO_CONTROLLER, batteryChar, 41);
    REQUIRE(test_cntrlrAlerted == 1);
    REQUIRE(test_cntrlrBrchType == TOO_HIGH);
}

TEST_CASE("Test alerter for  MED_ACTIVE_COOLING normal"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;
    test_cntrlrAlerted = 0;
    test_emailAlerted = 0;
    alertTypeList[TO_CONTROLLER] = &cntrlrAlertMock;
    alertTypeList[TO_EMAIL] = &emailAlertMock;

    checkAndAlert(TO_EMAIL, batteryChar, 30);
    REQUIRE(test_emailAlerted == 1);
    REQUIRE(test_emailBrchType == NORMAL);

    checkAndAlert(TO_CONTROLLER, batteryChar, 30);
    REQUIRE(test_cntrlrAlerted == 1);
    REQUIRE(test_cntrlrBrchType == NORMAL);
}

TEST_CASE("Test alerter for  MED_ACTIVE_COOLING low breach"){

    BatteryCharacter batteryChar;
    batteryChar.coolingType = MED_ACTIVE_COOLING;
    test_cntrlrAlerted = 0;
    test_emailAlerted = 0;
    alertTypeList[TO_CONTROLLER] = &cntrlrAlertMock;
    alertTypeList[TO_EMAIL] = &emailAlertMock;

    checkAndAlert(TO_EMAIL, batteryChar, -1);
    REQUIRE(test_emailAlerted == 1);
    REQUIRE(test_emailBrchType == TOO_LOW);


    checkAndAlert(TO_CONTROLLER, batteryChar, -1);
    REQUIRE(test_cntrlrAlerted == 1);
    REQUIRE(test_cntrlrBrchType == TOO_LOW);
}
