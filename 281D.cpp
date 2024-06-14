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
    ll N, K, D; cin >> N >> K >> D;
    vll a(N); rep(N) cin >> a[i];

    vvvll dp(N+1, vvll(K+1, vll(D, -1)));
    dp[0][0][0] = 0;

    rep(i,N){
        rep(j,K+1){
            rep(k,D){
                if(dp[i][j][k] == -1) continue;
                dp[i+1][j][k] = max(dp[i][j][k], dp[i+1][j][k]);
                if(j!=K)
                dp[i+1][j+1][(k+a[i])%D] = max(dp[i][j][k] + a[i], dp[i+1][j+1][(k+a[i])%D]);
            }
        }
    }

    cout << dp[N][K][0] << endl;
}