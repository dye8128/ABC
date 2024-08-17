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
using vvvll = vvc<vll>;
using vvpll = vvc<pll>;
using pqueue = priority_queue<ll, vll, greater<ll>>;

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
    vvvll a(n, vvll(n, vll(n)));
    rep(i,n) rep(j,n) rep(k,n) cin >> a[i][j][k];
    vvvll sum(n+1, vvll(n+1, vll(n+1, 0)));
    rep(i,n) rep(j,n) rep(k,n) 
    sum[i+1][j+1][k+1] = sum[i+1][j+1][k] + sum[i+1][j][k+1] + sum[i][j+1][k+1] - sum[i][j][k+1] - sum[i][j+1][k] - sum[i+1][j][k] + sum[i][j][k] + a[i][j][k];
    ll q; cin >> q;
    // rep(i,n+1) {rep(j,n+1) {rep(k,n+1) cout << sum[i][j][k] << " "; cout << endl;} cout << endl;}
    rep(q){
        ll lx, rx, ly, ry, lz, rz; cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--; ly--; lz--;
        cout << sum[rx][ry][rz] - sum[lx][ry][rz] - sum[rx][ly][rz] - sum[rx][ry][lz] + sum[lx][ly][rz] + sum[lx][ry][lz] + sum[rx][ly][lz] - sum[lx][ly][lz] << endl;
    }
}