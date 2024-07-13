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

ll pow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

ll pow2(ll x, ll n){
    ll res = 1;
    rep(n) {
        res *= x;
        if(res > 1e18) return 2e18;
    }
    return res;
}

ll binary_search(ll n, ll m){
    ll ok = 1, ng = pow(10, 18/m)+1;
    // cout << ng << endl;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(pow(mid,m) <= n) ok = mid;
        else ng = mid;
    }
    return ok; 
}

int main() {
    // 60以下の素数
    vll prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    ll n; cin >> n;
    ll ans = 0;
    // cout << LONG_MAX << endl;
    each(p, prime){
        ll tmp = binary_search(n, p);
        if(p > 3){
            tmp = 1;
            while(pow(tmp, p) <= n){
                tmp += 1;
            }
            tmp--;
        }
        if(p > 30){
            tmp = 1;
            while(pow2(tmp, p) <= n){
                tmp += 1;
            }
            tmp--;
        }
        ans += tmp;
        set<ll> s;
        rep(i,2,p){
            ll k = 1;
            while(pow(k, i) <= tmp){
                s.insert(pow(k, i));
                k += 1;
            }
            // cout << p << " " << i << " " << s.size() << endl;
        }
        ans -= s.size();
        // cout << p << " " << tmp - s.size() << endl;
    }
    cout << ans << endl;
}