#include "big_int.hpp"
#include <time.h>

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

    tm = clock() - tm;
    std::cout << "FAT " << x << " " << " = " << a.toStr() << std::endl;
    std::cout << "in: " << (float)tm/CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "output length: " << a.toStr().size() << " digits" << std::endl;
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
        fat = 25;
    }

    print_fac(fat);

    return 0;
}