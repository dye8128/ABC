#include <bits/stdc++.h>
#include <atcoder/all>
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

using namespace atcoder;

int main() {
    ll n, m; cin >> n >> m;
    vll a(m), b(m), c(m); 
    rep(m){ 
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    vll ind(m);
    iota(all(ind), 0);
    sort(all(ind), [&](const ll i, const ll j){return c[i] < c[j];});
    dsu d(n);
    ll i = 0;
    ll ans = 0;
    while(d.size(0) < n){
        // cout << i << ":" << a[ind[i]] << " " << b[ind[i]] << ", size = " << d.size(0) << endl;
        if(!d.same(a[ind[i]],b[ind[i]])){
            d.merge(a[ind[i]], b[ind[i]]);
        }else{
            ans += max(0ll, c[ind[i]]);
        }
        i++;
    }
    while(i < m){
        ans += max(0ll, c[ind[i]]);
        i++;
    }
    cout << ans << endl;
}