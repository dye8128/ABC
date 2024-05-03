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
    ll n, m; cin >> n >> m;
    vvll g(n, vll(n, -1));
    for(ll i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a][b] = c;
        g[b][a] = c;
    }
    vll v(n);
    for(ll i = 0; i < n; i++){
        v[i] = i;
    }
    ll M = 0;
    do{
        ll tmp = 0;
        for(ll i = 0; i < n - 1; i++){
            ll c = g[v[i]][v[i+1]];
            if(c == -1){
                break;
            }else{
                tmp += c;
            }
        }
        M = max(M, tmp);
    }while(next_permutation(v.begin(),v.end()));
    cout << M << endl;
}