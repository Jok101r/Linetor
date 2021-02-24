#include <iostream>
#include <vector>
#include "linetor.h"
#include "catch2/catch_all.hpp"

//TEST_CASE("Vector")
//{
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
////    vec.push_back(50);
////    vec.push_back(100);
//    BENCHMARK("empty"){
//            return vec.empty();
//    };
//    BENCHMARK("Swap"){
//            return vec.swap(vec1);
//    };
//}

TEST_CASE("Linetor") {
    linetor<int> line1;
    //line1.push_back(10);

    linetor<int> lines;
    REQUIRE(lines.length() == 0);

    linetor<int> lines;
    REQUIRE(lines.length() == 0);

    lines.push_back(50);
    REQUIRE(lines.length() == 1);

    lines.push_back(100);
    REQUIRE(lines.length() == 2);

//    for (int i=0; i<56; ++i)
//    {
//        lines.push_back(i);
//    }

//    lines.push_back(111);
//    lines.push_back(100);
//    lines.push_back(100);
//    lines.push_back(100);
//    lines.push_back(100);


//    BENCHMARK("pop back")
//    {
//        return lines.pop_back();
//    };
//    BENCHMARK("pop back"){
//        return lines.pop_back();
//    };
//    // not working push_bach on my macbook
//    BENCHMARK("push back 5")
//    {
//        return lines.push_back(5);
//    };
//    BENCHMARK("push back 50")
//    {
//        return lines.push_back(50);
//    };
//    BENCHMARK("push back 100")
//    {
//        return lines.push_back(100);
//    };
//    BENCHMARK("empty")
//    {
//        return lines.empty();
//    };
    //not working swap

    BENCHMARK("Swap")
    {
        return lines.swap(line1);
    };

    lines.swap(lines);

}

int main( int argc, char* argv[] )
{
//    linetor<int> line;
//    line.push_back(1);
//    line.push_back(20);
//    line.push_back(30);

//    line2.pop_back();


//    for (int run = 0; run < line2.length(); run++)
//        std::cout << " "<< line2[run];

    //std::cout << (line1 < line2) << (line1 > line2) <<std::endl;



    return 0;


}
