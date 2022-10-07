#include<iostream>
using namespace std;

long long int N = 1473907063;
long long int a = 1319;
long long int p = 19427;
long long int q = 75869;
long long int inv_a = 93859127;

long long int power(long long int x,long long int y,long long int p){
   long long int res = 1;
   while (y > 0) {
      if (y % 2 == 1){
         res = (res * x)%p;
      }
      y = y >> 1;
      x = (x * x)%p;
   }
   return res % p;
}

int main(){
   long long int encrypted_msg;
   cin >> encrypted_msg;

   long long int decrpt = power(encrypted_msg,inv_a,N);
   //cout << decrpt << endl;
   
   int a = decrpt/(1000000);
   int b = (decrpt - 1000000*(a))/10000;
   int c = (decrpt - 1000000*(a) - 10000*b)/100;
   int d = decrpt%100;
   // cout << a << endl;
   // cout << b << endl;
   // cout << c << endl;
   // cout << d << endl;
   cout << char(a+38) << char(b+38) << char(c+38) << char(d+38) << endl;
}