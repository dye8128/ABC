#include <iostream>
using namespace std;

int main() {
   int n, t = 0, a = 0;
   string s;
   cin >> n >> s;

   for( int i = 0; i < n; i++){
    if( s.at(i) == 'T') t++;
    else a++;
   } 
   if( t == a ){
    if( s.at(n-1) == 'T') cout << "A" << endl;
    else cout << "T" << endl;
   }else if( t > a ) cout << "T" << endl;
   else cout << "A" << endl;
}