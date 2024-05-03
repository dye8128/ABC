#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   cin >> a.at(0);
   for( int i = 1; i < n; i++){
    cin >> a.at(i);
    if(a.at(i-1) > a.at(i)){
        int j = 0;
        do{
            cout << a.at(i-1) - j << " ";
            j++;
        }while( a.at(i-1) - j > a.at(i));
    }else{
        int j = 0;
        do{
            cout << a.at(i-1) + j << " ";
            j++;
        }while( a.at(i-1) + j < a.at(i));
    }
   }
   cout << a.at(n-1) << endl;
}