#include <iostream>
#include <vector>

#include "smart_ptr.h"

int main(int argc, char *argv[])
{
    std::cout << "Smart pointers." << std::endl;

    std::cout << "Part 1. Unique pointers." << std::endl;
    {
        es::unique_ptr<std::vector<int>> up1(new std::vector<int>{42});
        es::unique_ptr<std::vector<int>> up2 = up1;
        up1 = up1;
        std::cout << "Object up2: " << (*up2).size() << std::endl;
        up1 = up2;
        std::cout << "Object up1: " << (*up1).size() << std::endl;
        es::unique_ptr<std::vector<int>> up3;
        up3 = up1;
        std::cout << "Object sp3: " << up3->size() << std::endl;
    }

    std::cout << "\nPart 2. Shared pointers." << std::endl;
    {
        es::shared_ptr<int> sp1(new int(1));
        es::shared_ptr<int> sp2, sp3;
        sp2 = sp1;
        sp3 = sp1;
        es::shared_ptr<int> sp4(new int(1));
        es::shared_ptr<int> sp5(new int(1));
    }

    return 0;
}
