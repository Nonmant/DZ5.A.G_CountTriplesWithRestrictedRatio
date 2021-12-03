#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "5 2\n"
                "1 1 2 2 3"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    INFO(buffer.str());
    REQUIRE(buffer.str() ==
            "9"
    );
}

TEST_CASE("tesm 030", ""){
    std::ifstream input( "../030", std::ofstream::in);
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "960385302450000"
    );
}

TEST_CASE("mine", ""){
    std::stringstream input(
            "7 2\n"
            "1 1 1 1 2 2 3\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "10"
    );
}

TEST_CASE("3 same numbers", ""){
    std::stringstream input(
            "3 2\n"
            "1 1 1\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "1"
    );
}

TEST_CASE("4 same numbers", ""){
    std::stringstream input(
            "4 2\n"
            "1 1 1 1\n"
    );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
            "1"
    );
}
