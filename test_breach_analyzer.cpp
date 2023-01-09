#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "product_config.h"
#include "breach_analyzer.h"

TEST_CASE("Value less than lower limit", "[inferBreach]") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("Value between the limit", "[inferBreach]") {
  REQUIRE(inferBreach(22, 20, 30) == NORMAL);
}

TEST_CASE("Value greater than the upper limit", "[inferBreach]") {
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
}

TEST_CASE("Value equal to lower limit", "[inferBreach]") {
  REQUIRE(inferBreach(20, 20, 30) == NORMAL);
}

TEST_CASE("Value equal to upper limit", "[inferBreach]") {
  REQUIRE(inferBreach(30, 20, 30) == NORMAL);
}

TEST_CASE("Check ouptut of interface function", ["classifyTemperatureBreach"]){
    REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 20) == NORMAL);
}
