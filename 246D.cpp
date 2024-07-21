#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
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

ll pow(ll a, ll b){
    ll ans = 1;
    rep(b){
        ans *= a;
    }
    return ans;
}

ll cal (ll a, ll b){
    ll ans = 0;
    rep(i,4){
        ans += pow(a, i) * pow(b, 3-i);
        if(ans >= 2e18) break;
    }
    return ans;
}

int main() {
    ll n; cin >> n;
    ll ans = 1ll << 60;
    rep(i, 1e6){
        ll a = i;
        ll ok = 1e6, ng = -1;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            if(cal(mid, a) >= n){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ans = min(ans, cal(ok, a));
    }
    cout << ans << endl;
}