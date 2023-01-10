#include <stdio.h>
#include <string.h>
#include "test/catch.hpp"
#include "product_config.h"
#include "send_alert.h"

char printStr[50];

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
