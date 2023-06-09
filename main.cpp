#include "big_int.hpp"
#include <time.h>
#include <thread>

void print_output(int x, BI& a, clock_t tm)
{
    tm = clock() - tm;
    std::cout << "FAT "  << x << std::endl;
    std::cout << a.toStr() << std::endl;
    std::cout << "in: " << (float)tm/CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "output length: " << a.toStr().size() << " digits" << std::endl;
}

void print_fac(int x)
{
    int i = x-1;
    BI a = x;
    clock_t tm = clock();

    if (x < 1)
    {
        return;
    }

    while(i > 0)
    {
        a = a * i;
        i--;
    }

    print_output(x,a,tm);
}

int main(int argc, char **argv)
{
    int fat = 0;
    if (argc > 1)
    {
        sscanf(argv[1], "%d", &fat);
    }
    else
    {
        fat = 10000;
    }

    print_fac(fat);

    return 0;
}