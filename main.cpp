#include <iostream>
#include <vector>
#include <linetor.h>

int main()
{
    std::vector<int> it;
;

    linetor<int> line1;
    line1.push_back(10);
    line1.push_back(2);
    line1.push_back(3);
    line1.push_back(4);

    for (int run = 0; run < line1.length(); run++)
        std::cout << " "<< line1[run];

    std::cout <<"\n\n";
    linetor<int> line2;
    line2.push_back(77);
    line2.push_back(6);
    line2.push_back(5);
    line2.push_back(5);

    for (int run = 0; run < line2.length(); run++)
        std::cout << " "<< line2[run];

    //line1.swap(line2);
    std::cout <<"\n\n";

    for(auto run : line2)
        std::cout << run;


    return 0;


}
