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

using namespace atcoder;
using mint = modint998244353;

int main() {
    ll n; cin >> n;
    vll a(n); rep(n) cin >> a[i];
    vll b(n); rep(n) cin >> b[i];
    vector dp(n+1, vc<mint>(5001));
    mint ans = 0;
    vll ind(n);
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j){return a[i] < a[j];});
    vll b1(n);
    rep(n) b1[i] = b[ind[i]]; b = b1;
    sort(all(a));

    dp[0][b[0]] = 1; ans += (a[0] >= b[0]);
    rep(i, 1, n){
        dp[i][b[i]] = 1;
        rep(j, 5001-b[i]){
            dp[i][j+b[i]] += dp[i-1][j];
        }
        rep(j, a[i]+1){
            ans += dp[i][j];
        }
        rep(j, 5001){
            dp[i][j] += dp[i-1][j];
        }
    }
    cout << ans.val() << endl;
}