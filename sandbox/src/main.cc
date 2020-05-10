#include <chip/core.h>
#include <chip/main.h>
#include <iostream>

int main()
{
    int five = returnFive();
    int eight = returnEight();

    std::cout << five << std::endl;
    std::cout << eight << std::endl;

    return 0;
}