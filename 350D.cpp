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

void cal(vll &check,ll& c, ll &v, vvll& f, ll i){
    if(f[i].size() == 0){
        check[i] = 1;
        c++;
        v++;
        return;
    }
    each(vv, f[i]){
        if(check[vv] == 0){
            c++;
            v++;
            check[vv] = 1;
            // cout << c << v << endl;
            cal(check, c, v, f, vv);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vll a(m), b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    vvll f(n,vll());
    rep(i,m){
        f[a[i]].emplace_back(b[i]);
        f[b[i]].emplace_back(a[i]);
    }
    vll check(n,0);
    ll c = 0;
    vll g;// 各グラフの頂点数
    while(c < n){
        ll v = 0;
        ll i = 0;
        while(check[i]) i++;
        cal(check, c, v, f, i);
        g.emplace_back(v);
    }
    ll ans = 0;
    each(v, g){
        ans += v * (v - 1) / 2;
    }
    ans -= m;
    cout << ans << endl;
}