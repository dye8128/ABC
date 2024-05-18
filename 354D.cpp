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
    ll a,b,c,d; cin >> a >> b >> c >> d;
    a += ll(1e10); b += ll(1e10); c += ll(1e10); d += ll(1e10);
    ll ma = a%4, qa = a/4, mc = c%4, qc = c/4;
    // cout << ma << " " << qa - 2500000000 << " " << mc << " " << qc - 2500000000 << endl;

    ll ans = 4 * (qc - qa) * (d - b);
    // cout << ans << endl;

    vvll r = {{1,2,1,0},{2,1,0,1}};
    ll tmp = 0;
    rep(i,ma) tmp -= r[0][i] + r[1][i];
    rep(i,mc) tmp += r[0][i] + r[1][i];
    ans += (d-b)/2 * tmp;
    // cout << ans << endl;

    if((d-b) % 2 == 1){
        // cout << "odd" << endl;
        rep(i,ma) ans -= r[d%2][i];
        rep(i,mc) ans += r[d%2][i];
    }
    cout << ans << endl;
}