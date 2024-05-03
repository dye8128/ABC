#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if(a < b) swap(a, b);
    if(a - b == 1 && a % 3 != 1){
        cout << "Yes" <<endl;
    }else{
        cout << "No" << endl;
    }
}