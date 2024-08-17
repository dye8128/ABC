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
using vvvll = vvc<vll>;
using vvpll = vvc<pll>;
using pqueue = priority_queue<ll, vll, greater<ll>>;

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

int log2LL (ll n) {
    int x = 0;
    while (n >>= 1) x++;
    return x;
} 

int main() {
    ll n, k; cin >> n >> k;
    vint x(n); rep(n) {cin >> x[i]; x[i]--;}
    vint a(n); rep(n) cin >> a[i];
    vvint dp(n, vint(log2LL(k)+1, 0));
    // cout << log2LL(k) << endl;
    rep(n) dp[i][0] = x[i];
    rep(i, 1, log2LL(k)+1){
        rep(j,n){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    // rep(n) cout << dp[i][1] << " "; cout << endl;
    rep(n){
        int ans = i;
        ll ki = k;
        int ind = 0;
        while(ki > 0){
            if(ki & 1) ans = dp[ans][ind];
            ind++;
            ki >>= 1;
        }
        cout << a[ans] << " ";
    }
    cout << endl;
}