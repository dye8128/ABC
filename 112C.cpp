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
    struct info {
        ll x, y, h;
    };
    vc<info> v(n);
    rep(n) cin >> v[i].x >> v[i].y >> v[i].h;
    sort(all(v), [](info a, info b){return a.h > b.h;});
    rep(x,101) rep(y,101) {
        ll h = v[0].h + abs(v[0].x - x) + abs(v[0].y - y);
        rep(i,1,n) {
            if (v[i].h == 0) {
                if (h > abs(v[i].x - x) + abs(v[i].y - y)) {h = -1; break;}
            } else {
                if (h != v[i].h + abs(v[i].x - x) + abs(v[i].y - y)) {h = -1; break;}
            }
        }
        if(h > 0){
            cout << x << " " << y << " " << h << endl;
            return 0;
        }
    }

}