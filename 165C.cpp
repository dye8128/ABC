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

vll a,b,c,d;
ll ans = 0, m;

void calc(ll n, vll &v){
    if(n + 1 == v.size()){
        ll sum = 0;
        // each(i,v) cout << i << " "; cout << endl;
        rep(i,d.size()){
            if(v[b[i]] - v[a[i]] == c[i]) sum += d[i];
        }
        ans = max(ans, sum);
        return;
    }
    rep(i, v.back(), m+1){
        v.emplace_back(i);
        calc(n, v);
        v.pop_back();
    }
}


int main() {
    ll n, q; cin >> n >> m >> q;
    a.assign(q,0); b.assign(q,0); c.assign(q,0); d.assign(q,0);
    vll v = {1};
    rep(q) {cin >> a[i] >> b[i] >> c[i] >> d[i];}
    calc(n, v);
    cout << ans << endl;
}