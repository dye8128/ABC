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

void yesno(bool flag){cout << (flag ? "Yes" : "No") << endl;}

int main() {
    ll t; cin >> t;
    rep(i,t){
        ll n, x, k; cin >> n >> x >> k;
        ll ans = 0;
        while(x > 0 && k >= 0){
            ll dimX = log2(x);
            ll dimN = log2(n);
            if(dimX + k < dimN){
                ans += 1<<k;
            }else if(dimX + k == dimN){
                if((n>>k) < x){
                    ans += 1<<k;
                }else if((n>>k) == x){
                    ans += n % dimX + 1;
                }
            }
            x /= 2; k--;
        }
        cout << ans << endl;
    }
    // rep(i,1,16) cout << "log" << i  << "=" << int(log10(i)) << endl;
}