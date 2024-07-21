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

using mint = atcoder::modint998244353;

int main() {
    ll n, m, k, s, t, x; cin >> n >> m >> k >> s >> t >> x;
    vvll g(n+1);
    rep(m) {
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vc<vvc<mint>> dp(n+1, vvc<mint>(k+1, vc<mint>(2)));
    dp[s][0][0] = 1;
    rep(i, k){
        rep(j, 1, n+1){
            each(v, g[j]){
                if(v == x){
                    dp[v][i+1][1] += dp[j][i][0];
                    dp[v][i+1][0] += dp[j][i][1];
                }else{
                    dp[v][i+1][0] += dp[j][i][0];
                    dp[v][i+1][1] += dp[j][i][1];
                }
            }
        }
    }
    cout << dp[t][k][0].val() << endl;
}