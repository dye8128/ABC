#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> s(n);
    vector<int64_t> a(n);
    for(int i = 0; i < n; i++ ) {
        cin >> s.at(i) >> a.at(i);
    }
    int64_t min = pow(10,9);
    int minnum = 0;
    for(int i = 0; i < n; i++) {
        if(min > a.at(i)){
            min = a.at(i);
            minnum = i;
        }
    }
    //cout << min << minnum << endl;
    for(int i = 0; i < n; i++) {
        cout << s.at((i + minnum) % n) << endl;
    }
}