#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include "linetor.h"
#include "catch2/catch_all.hpp"

//TEST_CASE("Vector") {
//    std::vector<int> vec;

//    std::vector<int> vec1 = { 1, 3 , 5};

//    //мне кажется, что здесь чек не нужен
//    //CHECK();
//    //CHECK();
//    BENCHMARK("push back 5"){
//            return vec.push_back(5);
//    };
//    BENCHMARK("push back 50"){
//            return vec.push_back(50);
//    };
//    BENCHMARK("push back 100"){
//            return vec.push_back(100);
//    };
//    BENCHMARK("pop back"){
//            return vec.pop_back();
//    };
//    BENCHMARK("pop back"){
//            return vec.pop_back();
//    };
//    vec.push_back(50);
//    vec.push_back(100);
//    BENCHMARK("empty"){
//            return vec.empty();
//    };
//    BENCHMARK("Swap"){
//            return vec.swap(vec1);
//    };
//}

TEST_CASE("Linetor") {
    linetor<int> line;

    linetor<int> line1;


    // not working push_bach
//    BENCHMARK("push back 5"){
//            return line.push_back(5);
//    };
//    BENCHMARK("push back 50"){
//            return line.push_back(50);
//    };
//    BENCHMARK("push back 100"){
//            return line.push_back(100);
//    };
    BENCHMARK("pop back"){
            return line.pop_back();
    };
    BENCHMARK("pop back"){
            return line.pop_back();
    };
    line.push_back(50);
    line.push_back(100);
    BENCHMARK("empty"){
            return line.empty();
    };
    //not working swap
    BENCHMARK("Swap"){
            return line.swap(line);
    };
}
int main( int argc, char* argv[] )
{
    linetor<int> line;
    line.push_back(1);
    line.push_back(20);
    line.push_back(30);

    for(auto & i : line)
        std::cout << i << " ";
    std::cout<<"\n";
    for(int i=0; i<line.length(); i++)
        std::cout << line[i] << " ";
    Catch::Session session;

    int returnCode = session.applyCommandLine( argc, argv );
    if( returnCode != 0 )
          return returnCode;

    int numFailed = session.run();

    return numFailed;


}
