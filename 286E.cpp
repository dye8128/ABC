#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using vc = vector<T>;
template<class T>using vvc = vc<vc<T>>;
using vint = vc<int>;
using vll = vc<ll>;
using vstr = vc<str>;
using vpint = vc<pint>;
using vpll = vc<pll>;
using vbool = vc<bool>;
using vvint = vvc<int>;
using vvll = vvc<ll>;

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n)          for(ll i = 0; i < (n); ++i)
#define rep2(i, n)       for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b)    for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define each1(a)       for(auto&& i : a)
#define each2(i,a)     for(auto&& i : a)
#define each3(x,y,a)   for(auto&& [x, y] : a)
#define each4(x,y,z,a) for(auto&& [x, y, z] : a)
#define each(...) overload4(__VA_ARGS__, each4, each3, each2, each1)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()

void yesno(bool flag){cout << (flag ? "Yes" : "No") << endl;}

int main() {
    ll n; cin >> n;
    vll a(n); rep(n) cin >> a[i];
    vstr s(n); rep(n) cin >> s[i];
    vvll dist(n, vll(n, 1e18));
    vvll val(n, vll(n, 0));
    rep(n) dist[i][i] = 0;
    rep(n) rep(j, n){
        if(s[i][j] == 'Y') {dist[i][j] = 1; val[i][j] = a[j];}
    }
    rep(n) rep(j, n) rep(k, n){
        if(dist[j][k] > dist[j][i] + dist[i][k]){
            dist[j][k] = dist[j][i] + dist[i][k];
            val[j][k] = val[j][i] + val[i][k];
        }else if(dist[j][k] == dist[j][i] + dist[i][k]){
            val[j][k] = max(val[j][k], val[j][i] + val[i][k]);
        }
    }
    ll q; cin >> q;
    rep(q){
        ll x, y; cin >> x >> y;
        --x, --y;
        if(dist[x][y] == 1e18) cout << "Impossible" << endl;
        else cout << dist[x][y] << " "<< val[x][y] + a[x] << endl;
    }
}