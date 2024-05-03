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
    map<int, vint> waiting;
    // v0 = index, v1 = 累計パターン, v2 = 一致したindexの個数
    ll ans = 0;
    int n; cin >> n;
    vint a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < n; i++){
        int tmp = a.at(i);
        if(waiting.count(tmp)){
            auto it = waiting.find(tmp);
            auto v = it->second;
            int v0 = v[0], v1= v[1], v2= v[2];
            v1 += (i - v0 - 1) * v2;
            v2++;
            v0 = i;
            waiting[tmp] = {v0,v1,v2};
            ans+=v1;
        }else{
            waiting[tmp] = {i, 0, 1};
        }
    }
    // for(auto v:waiting){
    //     cout << v.first << " " << v.second[1] << endl;
    // }
    // for(int i = 0; i < n; i++){
    //     int tmp = a.at(i);
    //     if(waiting.count(tmp) > 0){
    //         auto rng = waiting.equal_range(tmp);
    //         for(auto it = rng.first; it != rng.second; it++){
    //             ans += (i - it->second - 1);
    //         }
    //     }
    //     waiting.insert({tmp, i});
    // }
    cout << ans << endl;
}