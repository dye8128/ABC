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
    int h, x; cin >> h >> x;
    int tmp = x - h;
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        if(p >= tmp){
            cout << i + 1 << endl;
            return 0;
        }
    }
}