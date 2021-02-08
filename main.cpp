#include <iostream>
#include <vector>
#include <linetor.h>

int main()
{
    std::vector<int> it;
;

    linetor<int> line1;
    //line1.push_back(10);

    std::cout << line1.empty();

    std::cout <<"\n\n";
    linetor<int> line2;
    line2.push_back(77);
    line2.push_back(6);

        line2.pop_back();
            line2.push_back(5);

    //line2.push_back(5);

    for (int run = 0; run < line2.length(); run++)
        std::cout << " "<< line2[run] << "\t" << line2.getDate() + run << std::endl;


    //line1.swap(line2);
//    std::cout <<"\n\n";

//    line2.pop_back();


//    for (int run = 0; run < line2.length(); run++)
//        std::cout << " "<< line2[run];

    //std::cout << (line1 < line2) << (line1 > line2) <<std::endl;



    return 0;


}
