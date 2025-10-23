#include<stdio.h>

long long unsigned f(int n)
{
    long long unsigned r = 0;
    if (n==1) {// base case
        return 1;
    }
    r = f(n-1) + f(n-1) + 1;

    return r;
}
int main()
{
    long long unsigned r = f(21);
    printf("%llu\n",r);
    return 0;   
}
