#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using vc = vector<T>;
template<class T>using vvc = vc<vc<T>>;
template<class T>using vvvc = vc<vvc<T>>;
using vint = vc<int>;
using vll = vc<ll>;
using vstr = vc<str>;
using vpint = vc<pint>;
using vpll = vc<pll>;
using vbool = vc<bool>;
using vvint = vvc<int>;
using vvll = vvc<ll>;
using vvvll = vvvc<ll>;

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
    vll x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vvvll g_(2);
    rep(i, n){
        g_[(x[i] + y[i])%2].emplace_back(vll({x[i], y[i]}));
    }
    ll ans = 0;
    rep(k, 2){
        auto g = g_[k];
        vll a, b;
        each(v, g){
            ll vx = v[0], vy = v[1];
            a.emplace_back(vx+vy);
            b.emplace_back(vx-vy);
        }
        ll m = a.size();
        if(m == 0) break;

        sort(all(a)); sort(all(b));
        
        vll sum_a(m,0), sum_b(m,0);
        sum_a[0] = a[0]; sum_b[0] = b[0];
        rep(i,1,m){
            sum_a[i] = sum_a[i - 1] + a[i];
            sum_b[i] = sum_b[i - 1] + b[i];
        }

        rep(i,1,m){
            ans += (i * a[i] - sum_a[i - 1]) / 2;
            ans += (i * b[i] - sum_b[i - 1]) / 2;
        }
    }
    cout << ans << endl;
}