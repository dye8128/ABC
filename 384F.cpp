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

ll cal(ll n){
    ll cnt = 0;
    while(n % 2 == 0){
        n /= 2;
        cnt++;
    }
    return cnt;
}

int main() {
    ll n; cin >> n;
    vll a(n); rep(n) cin >> a[i];   
    vvll dp(30,{0,0});
    ll ans = 0;
    rep(n){
        ll cnt = cal(a[i]);
        dp[cnt][0] += a[i] >> cnt;
        dp[cnt][1]++;
        rep(j,cnt){
            if(dp[j][1] > 0) {
                ans += dp[j][0] + (a[i] >> j) * dp[j][1];
                // printf("i: %lld, j: %lld, dp[j][0]: %lld, a[i] >> j: %lld\n", i, j, dp[j][0], a[i] >> j);
            }
        }
        if(dp[cnt][1] > 0){
            ans += (dp[cnt][0] + (a[i] >> cnt) * dp[cnt][1]) / 2;
            // printf("i: %lld, cnt: %lld, dp[cnt][0]: %lld, a[i] >> cnt: %lld, dp[cnt][1]: %lld\n", i, cnt, dp[cnt][0], a[i] >> cnt, dp[cnt][1]);
        }
        rep(j,cnt+1,30){
            if(dp[j][1] > 0) {
                ans += (dp[j][0] << (j-cnt)) + (a[i] >> cnt) * dp[j][1];
                // printf("i: %lld, j: %lld, a[i] >> cnt: %lld, dp[j][0] << (j-cnt): %lld\n", i, j, a[i] >> cnt, dp[j][0] << (j-cnt));
            }
        }
    }
    // rep(30) cout << dp[i][0] << " " << dp[i][1] << endl;
    cout << ans << endl;
}