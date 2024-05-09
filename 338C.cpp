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
ll n;

ll binary(vll &q, vll &a, vll &b){
    ll ok = 0, ng = 1e7;
    ll m;
    while(abs(ok - ng) > 1){
        m = (ok+ng)/2;
        ll low = 0, high = 1e7;
        rep(i,n){
            if(a[i] - b[i] > 0){
                if(q[i] - m * b[i] >= 0){
                    high = min(high, (q[i] - m * b[i]) / (a[i] - b[i]));
                }else{
                    high = -1;
                }
            }else if(a[i] - b[i] < 0){
                low = max(low, (m * b[i] - q[i] + b[i] - a[i] - 1) / (b[i] - a[i]));
            }else if(q[i] - m*b[i] < 0){
                low = 1e7;
            }
        }
        // cout << high << " " << low << endl;
        if(high - low >= 0 && high >= 0 && low <= m){
            ok = m;
        }else{
            ng = m;
        }
        // cout << "ok:" << ok << " ng:" << ng << endl;
    }
    return ok;
}

int main() {
    cin >> n;
    vll q(n), a(n), b(n);
    rep(i,n) cin >> q[i];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll ans = binary(q,a,b);
    cout << ans << endl;
}