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

int main() {
    ll n, x, y; cin >> n >> x >> y;
    vll a(n), b(n); rep(n) cin >> a[i] >> b[i];
    vc<vvll> dp(n+1, vvll(n+1, vll(x+1, 1e9)));
    dp[0][0][0] = 0;
    rep(i, n){
        rep(j, n){
            rep(k, x+1){
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                if(k+a[i] <= x) dp[i+1][j+1][k+a[i]] = min(dp[i+1][j+1][k+a[i]], dp[i][j][k]+b[i]);
            }
        }
    }
    rep(n+1){
        rep(j, x+1){
            // cout << dp[n][i][j] << " ";
            if(dp[n][n-i][j] <= y){
                cout << min(n,n-i+1) << endl;
                return 0;
            }
        }
        // cout << endl;
    }
}