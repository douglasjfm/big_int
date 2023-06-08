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

void print_fac2(int x)
{
    int i = x-1, j = 1, x2 = x>>1;
    BI a = x, b = 1;
    clock_t tm = clock();

    if (x < 1)
    {
        return;
    }

    std::thread ta([&a,&i,&j](){
        while(i > j)
        {
            a = a * i;
            i--;
        }
        std::cout << "FIM A " << i << std::endl;
    });
    std::thread tb([&b,&j,&i](){
        while(j < i)
        {
            b = b * j;
            j++;
        }
        std::cout << "FIM B " << j << std::endl;
    });

    if (ta.joinable()) ta.join();
    if (tb.joinable()) tb.join();

    std::cout << "FIM C " << std::endl;
    
    a = a * b;

    std::cout << "FIM D" << std::endl;

    print_output(x,a,tm);
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

    if (argc == 3 || argc == 1) print_fac2(fat);
    else print_fac(fat);

    return 0;
}