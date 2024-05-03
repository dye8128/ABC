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
    vint a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    vvll pattern(n + 1, vll(3,0));
    ll ans = 0;
    // v0 = index, v1 = 累計パターン, v2 = 一致したindexの個数
    for(int i = 0; i < n; i++){
        int tmp = a[i];
        if(pattern[tmp][2]){
            pattern[tmp][1] += pattern[tmp][2] * (i - pattern[tmp][0] - 1);
            pattern[tmp][2] ++;
            pattern[tmp][0] = i;
            ans += pattern[tmp][1];
        }else{
            pattern[tmp] = {i,0,1};
        }
    }
    cout << ans << endl;
}