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
    vvint map(100, vint(100, 0));
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        int c, d; cin >> c >> d;
        for(int i = a; i < b; i++){
            for(int j = c; j < d; j++){
                map[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for(auto v:map){
        for(auto tmp: v){
            ans+=tmp;
        }
    }
    cout << ans << endl;
}