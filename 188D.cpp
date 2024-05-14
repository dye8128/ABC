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
    ll n, C; cin >> n >> C;
    vll a(n), b(n), c(n);
    rep(i,n)cin >> a[i] >> b[i] >> c[i];
    // time, cost, a or b 
    vc<tuple<ll,ll,ll>> tp;
    rep(i,n){
        tp.emplace_back(make_tuple(a[i]-1, c[i], 0ll));
        tp.emplace_back(make_tuple(b[i], c[i], 1ll));
    }
    sort(all(tp));
    // each(v,tp) cout << get<0>(v) << endl;
    ll costs = 0, t = 0, t0 = 0, ans = 0;
    rep(i,2 * n){
        t = get<0>(tp[i]);
        ans += min(C, costs) * (t - t0);
        if(get<2>(tp[i]) == 0){
            costs += get<1>(tp[i]);
        }else{
            costs -= get<1>(tp[i]);
        }
        t0 = t;
    }
    cout << ans << endl;
}