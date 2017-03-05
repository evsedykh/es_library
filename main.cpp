#include <iostream>
#include <vector>

#include "smart_ptr.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Smart pointers." << endl;
    es::unique_ptr<std::vector<int>> sp1(new std::vector<int>{42});
    es::unique_ptr<std::vector<int>> sp2 = sp1;
    sp1 = sp1;
    std::cout << "Object sp2: " << (*sp2).size() << std::endl;
    sp1 = sp2;
    std::cout << "Object sp1: " << (*sp1).size() << std::endl;
    es::unique_ptr<std::vector<int>> sp3;
    sp3 = sp1;
    std::cout << "Object sp3: " << sp3->size() << std::endl;

    return 0;
}
