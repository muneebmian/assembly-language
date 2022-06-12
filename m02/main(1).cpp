#include "../std_lib_facilities.h"
#include "RSA.h"
#include<climits>

int main()
{

     unsigned long long e,p, q, n, lambda, d, m, c;
     unsigned int seed;

     cout << "Enter a seed: ";
     cin >> seed;
     
     srand(seed);

     p = getPrime(UCHAR_MAX,USHRT_MAX);
     
     q = getPrime(UCHAR_MAX,USHRT_MAX);
     cout << "p: " << p << endl;
     cout << "q: " << q << endl;
     
     n = p * q;
     cout << "n: " << n << endl;
     
     lambda = lcm(p-1,q-1);
     cout << "lambda: " << lambda << endl;
     
     e = getPrime(2, (lambda-1)); 

     while(lambda%e == 0)
     {
         e = getPrime(2,(lambda-1));

     }
     d = modInverse(e, lambda);

     cout << "e: " << e << endl;
     cout << "d: " << d << endl;

     cout << "Public key: n = " << n << " e = " << e << endl;
     cout << "Private key: n = " << n << " d = " << d << endl;

     cout << "Enter a positive number less than " << n << ": "<< endl;
     cin >> m;

     while (m < 0 || m > n)
     {
         cout << "Enter a positive number less than " << n << ": "<< endl;
         cin >> m;
     }

     c = modExp(m,e,n);
     cout << "Cipher: " << c << endl;
     cout << "Decrypted cipher: " << modExp(c,d,n) << endl;


    return 0;
}
