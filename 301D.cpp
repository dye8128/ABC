#include <bits/stdc++.h>
using namespace std;

int main() {
   string s;
   int N;
   int ans = 0;
   vector<int> n2(61, 0);
   cin >> s >> N;
   int n;
   n = N;
   int i = 0;
   do{
    n2.at(i) = n % 2;
    n /= 2;
    i++;
   }while(n != 0);

   int keta;
   for(int i = 0; i < 61; i++){
    if( n2.at(i) == 1) keta = i;
   }
   //cout << keta << endl;

   /*int flag = 0;
   for(int i = 0; i < keta; i++){
    if( s.at(keta - i) != '0') flag = 1;
   }
   if( flag == 0 ){
    cout << "-1" << endl;
   }*/
   
   for(int i = 0; i < s.size(); i++){
    if( i < keta ){
        if( s.at(i) != '0' ) ans+=pow(2, i);
    }else{
        if( s.at(i) == '1' ) ans+=pow(2, i);
    }
   }
   //cout << ans << endl;

   int ans2;
   ans2 = ans;

   if( keta < s.size() ){
    if( s.at(keta) != '0' ) ans2+=pow(2, i);
   }

   if( ans2 < N ){
    cout << ans2 << endl;
   }else if( ans < N ){
    cout << ans << endl;
   }else cout << "-1" << endl;

   //for(int i = 0; i < 61; i++) cout << n2.at(i) << " ";
}