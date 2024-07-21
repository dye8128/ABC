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
    ll n, m, q; cin >> n >> m >> q;
    vvll a(n, vll(n));
    rep(m){
        ll l, r; cin >> l >> r;
        a[l-1][r-1]++;
    }
    vvll s(n, vll(n));
    s[0][0] = a[0][0];
    rep(i,1,n) s[0][i] = s[0][i-1] + a[0][i];
    rep(i,1,n) s[i][0] = s[i-1][0] + a[i][0];
    rep(i,1,n){
        rep(j,1,n){
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    rep(q){
        ll p, q; cin >> p >> q;
        p--; q--;
        cout << s[q][q] + (p==0 ? 0 : (- s[p-1][q] - s[q][p-1] + s[p-1][p-1])) << endl;
    }
}