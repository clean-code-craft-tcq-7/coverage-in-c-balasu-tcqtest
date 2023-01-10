#include <stdio.h>
#include <string.h>
#include "test/catch.hpp"
#include "product_config.h"
#include "send_alert.h"

char printStr[100];

void printfunc(char* buff)
{
    strcpy(printStr, buff);
}
TEST_CASE("Alert Controller Too Low Breach"){

    alertTypeList[TO_CONTROLLER](TOO_LOW, &printfunc);
    REQUIRE(strcmp(printStr,"feed : 1\n") == 0);
}

TEST_CASE("Alert Controller Normal"){

    alertTypeList[TO_CONTROLLER](NORMAL, &printfunc);
    REQUIRE(strcmp(printStr,"feed : 0\n") == 0);
}

TEST_CASE("Alert Controller Too High Breach"){

    alertTypeList[TO_CONTROLLER](TOO_HIGH, &printfunc);
    REQUIRE(strcmp(printStr,"feed : 2\n") == 0);
}

TEST_CASE("Alert Mail Normal"){

    memset(printStr,0,100);
    alertTypeList[TO_EMAIL](NORMAL, &printfunc);
    REQUIRE(strlen(printStr) == 0);
}

TEST_CASE("Alert Mail Too Low"){

    alertTypeList[TO_EMAIL](TOO_LOW, &printfunc);
    REQUIRE(strcmp(printStr,"To: a.b@c.com\nHi, the temperature is too low\n") == 0);
}

TEST_CASE("Alert Mail Too High"){

    alertTypeList[TO_EMAIL](TOO_HIGH, &printfunc);
    REQUIRE(strcmp(printStr,"To: a.b@c.com\nHi, the temperature is too high\n") == 0);
}
