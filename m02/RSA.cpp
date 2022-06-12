#include "../std_lib_facilities.h"
#include "RSA.h"

bool isPrime(unsigned long long n)
{
    bool primeN = true;
    if(n==0 || n==1)
    {
        primeN = false;
    }
    for (long long unsigned i = 2; i <= sqrt(n); i++)
        {
            if ((n % i) == 0)
                {
                 primeN = false;

                }
        }
    return primeN;
}

unsigned long long getPrime(unsigned long long min, unsigned long long max)
{
    unsigned long long number = (rand() % (max - min + 1)) + min;
    while(!(isPrime(number)))
    {
        number = (rand() % (max - min + 1)) + min;

    }

    return number;
}


unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}
unsigned long long lcm(unsigned long long x, unsigned long long y)
{
    return (x*y) / gcd(x,y);
}
unsigned long long modInverse(unsigned long long e, unsigned long long lam)
{
    for(unsigned long long d = 1; d <= lam ;d++)
    {
        if((d*e) % lam == 1)
        {
            return d;
        }
    }
    return -1;
}
unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long n)
{
   unsigned long long ans = 1;
   for(unsigned long long i = 0; i < exp; i++)
      {
          ans = (ans * base) % n;
      }
   return ans;
}
