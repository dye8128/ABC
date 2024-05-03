#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    i64 n;
    cin >> n;
    vector<int> a;
    if(n < 1000) {
        cout << n << endl;
        return 0;
    }
    for(int i = 0; n != 0; i++) {
        a.push_back(n % 10);
        n /= 10;
    }
    for(int i = 0; i < a.size(); i++) {
        if(i < 3) {
            cout << a.at(a.size() - i - 1);
        }else{
            cout << "0";
        }
    }
    cout << endl;
}