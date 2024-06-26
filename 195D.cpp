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
    ll n,m,q; cin >> n >> m >> q;
    vll w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];
    vc<pll> x(m);
    rep(i, m){ 
        cin >> x[i].first;
        x[i].second = i + 1;
    }
    sort(all(x));
    vc<pll> wv(n);
    rep(i, n){
        wv[i] = {w[i], v[i]};
    }
    sort(all(wv));
    rep(_, q){
        ll l,r; cin >> l >> r;
        ll ans = 0;
        vll boxed(n,0);
        rep(i, m){
            ll j = 0, max_v = 0, max_j = -1;
            while(j < n && x[i].first >= wv[j].first){
                if(x[i].second >= l && x[i].second <= r){
                    break;
                }else{
                    if(boxed[j] == 0 && max_v < wv[j].second){
                        max_j = j;
                        max_v = wv[j].second;
                    }
                }
                j++;
            }
            ans += max_v;
            if(max_j >= 0) boxed[max_j] = 1;
        }
        cout << ans << endl;
    }
}