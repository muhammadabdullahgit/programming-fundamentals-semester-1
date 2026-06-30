#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"


TEST_CASE( "2: Q2", "[multi-file:2]" ) {
    SECTION( "Task 2: Sum_of_numbers" ) {
      int n=5; int ans=15;
      REQUIRE(ans == sumNumbers(n));
    }
}

TEST_CASE( "2: Q4", "[multi-file:2]" ) {
    SECTION( "Task 4: Sum of Digits" ) {
      int n=12345; int ans=15;
      REQUIRE(ans == sumDigits(n));
    }
}
