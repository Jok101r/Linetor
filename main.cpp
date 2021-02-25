#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include "linetor.h"
#include "catch2/catch_all.hpp"

TEST_CASE("Vector")
{
   std::vector<int> vec;

   std::vector<int> vec1 = { 1, 3 , 5};

   BENCHMARK("push back 5"){
           return vec.push_back(5);
   };
   BENCHMARK("push back 50"){
           return vec.push_back(50);
   };
   BENCHMARK("push back 100"){
           return vec.push_back(100);
   };
   BENCHMARK("pop back"){
           return vec.pop_back();
   };
   BENCHMARK("pop back"){
           return vec.pop_back();
   };
//    vec.push_back(50);
//    vec.push_back(100);
   BENCHMARK("empty"){
           return vec.empty();
   };
   BENCHMARK("Swap"){
           return vec.swap(vec1);
   };
}

TEST_CASE("Linetor")
{
    linetor<int> line1;
    
    linetor<int> lines;
    REQUIRE(lines.length() == 0);

    lines.push_back(50);
    REQUIRE(lines.length() == 1);

    lines.push_back(100);
    REQUIRE(lines.length() == 2);

    BENCHMARK("pop back")
    {
        return lines.pop_back();
    };
    BENCHMARK("pop back"){
        return lines.pop_back();
    };
    // not working push_bach on my macbook
    BENCHMARK("push back 5")
    {
        return lines.push_back(5);
    };
    BENCHMARK("push back 50")
    {
        return lines.push_back(50);
    };
    BENCHMARK("push back 100")
    {
        return lines.push_back(100);
    };
    BENCHMARK("empty")
    {
        return lines.empty();
    };

    BENCHMARK("Swap")
    {
        return lines.swap(line1);
    };

    lines.swap(lines);

}

int main(int argc, char* argv[])
{
    Catch::Session session;

    int returnCode = session.applyCommandLine( argc, argv );
    if( returnCode != 0 )
    {
        return returnCode;
    }

    int numFailed = session.run();

    return numFailed;
}
