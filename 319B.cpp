#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vint = vector<int>;
using vll = vector<ll>;
using vstr = vector<str>;
using vpint = vector<pair<int, int>>;
using vbool = vector<bool>;
using vvint = vector<vint>;
using vvll = vector<vll>;

int main() {
    int n; cin >> n;
    vint j_;
    for(int i = 1; i < 10; i++){
        int tmp = n % i;
        if(tmp == 0) j_.emplace_back(i);
    }
    // for(auto j : j_) cout << j;
    // cout << endl;
    for(int i = 0; i <= n; i++){
        bool flag = true;
        for(auto j : j_){
            int tmp = i % (n / j);
            if(tmp == 0){
                cout << j;
                flag = false;
                break;
            }
        }
        if(flag) cout << '-';
    }
    cout << endl;
}