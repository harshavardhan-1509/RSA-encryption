#include<iostream>
using namespace std;
static long long int N = 1473907063;
static long long int a = 1319;



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



long long int encrypt(string str){
   string s = "";
   for(int i = 0; int(str[i]) != 0; i++){
      s += to_string(int(str[i]) - 38);
   }
   //cout << "s = " << s << endl;
   string b = "";
   for(int i = 0; i < 8 ; i++){
      b += s[i]; 
   }
   //cout << "b = " << b << endl;
   long long int c = stoi(b);
   //cout << "message converter = " << c << endl;
   long long int ans = power(c,a,N) ;
   return ans;
} 

int main(){
   string message;
   cout << "Type what you want to send to other person." << endl;
   cout << "The input should be of fromat **** ,where * can take chars from a-z and A-Z" << endl;
   cin >> message;
   long long int enc = encrypt(message);
   cout << enc << endl;
}