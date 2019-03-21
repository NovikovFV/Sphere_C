#include <math.h>
#include <iostream>
#include "numbers.dat"

bool Pr_test(int test)
{
    if(test == 1)
        return false;
    double sqrt_test = sqrt(test);
    for(int i = 2; i <= sqrt_test; i++)
    {
        if(test % i == 0)
            return false;
    }
    return true;
}

size_t Search_pr(int a, int b)
{
    for(size_t i = 0; i < Size; i++)
    {
        if(Data[i] >= a)
        {
            size_t j = 0;
            for(; i < Size and Data[i] <= b; i++)
            {
                j += Pr_test(Data[i]);
            }
            return j;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc == 1)
        return -1;
    if(argc % 2 == 0 && argc > 1)
        return -1;

    for(int i = 1; i + 1 <= argc; i += 2)
    {
        int a = std::atoi(argv[i]);
        int b = std::atoi(argv[i + 1]);
        if(a > b)
        {
            std::cout << "0";
            return 0;
        }
        std::cout << Search_pr(a, b) << "\n";
    }
    return 0;
}
