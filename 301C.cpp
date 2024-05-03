#include <bits/stdc++.h>
using namespace std;

int main() {
   string s,t;
   int judge = 0;
   cin >> s >> t;
   int sat = 0;
   int tat = 0;
   vector<int> sc(26, 0), tc(26, 0);
   for( int i = 0; i < s.size(); i++ ){
    if( s.at(i) != '@') sc.at( s.at(i) - 'a')++;
    else sat++;
    if( t.at(i) != '@') tc.at( t.at(i) - 'a')++;
    else tat++;
   }

   for( int i = 0; i < 26; i++ ){
    if( i != 0 && i != 19 && i != 2 && i != 14 && i != 3 && i != 4 && i != 17){
     if( sc.at(i) == tc.at(i) ) judge++;
     else{
        cout << "No" << endl;
        return 0;
     }
    }else{
        if( sc.at(i) > tc.at(i) + tat){
        cout << "No" << endl;
        return 0;
        }
    }
   }

   cout << "Yes" << endl;


   /*for( int i = 0; i < 26; i++ ){
    cout << sc.at(i) << " ";
   }*/

}