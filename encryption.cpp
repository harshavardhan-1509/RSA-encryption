#include<iostream>
using namespace std;
long long int p = 19427;
long long int q = 75869;
long long int a = 1319;
long long int inv_a = 0;

long long int encryption(int* a){
   return 0;
}

long long int gcdExtended(long long int a,long long int b,long long int* x,long long int* y);
long long int modInverse(long long int A,long long int M);

long long int modInverse(long long int A,long long int M)
{
    long long int x, y;
    long long int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        return -1;
    else {
        long long int res = (x % M + M) % M;
        return res;
    }
}

long long int gcdExtended(long long int a,long long int b,long long int* x,long long int* y)
{
   if (a == 0) {
       *x = 0, *y = 1;
       return b;
   }
   long long int x1, y1;
   long long int gcd = gcdExtended(b % a, a, &x1, &y1);
   *x = y1 - (b / a) * x1;
   *y = x1;
   return gcd;
}
void initialize(){

}
int main(){   
   inv_a = modInverse(a,(p-1)*(q-1));
   cout << inv_a << endl;
   cout << (a*inv_a)%((p-1)*(q-1)) << endl;
   //cout  << p*q - (a*inv_a)%((p-1)*(q-1))<< endl;
   cout << p*q << endl;
}