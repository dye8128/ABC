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

int main() {
    ll n; cin >> n;
    str s; cin >> s;
    vector dp(n+1, vll(3, 0));

    // R, S, P
    rep(i,n){
        if(s[i] == 'R'){
            dp[i+1][0] = max(dp[i][1], dp[i][2]);
            dp[i+1][2] = max(dp[i][1], dp[i][0])+1;
        }
        if(s[i] == 'S'){
            dp[i+1][1] = max(dp[i][2], dp[i][0]);
            dp[i+1][0] = max(dp[i][2], dp[i][1])+1;
        }
        if(s[i] == 'P'){
            dp[i+1][2] = max(dp[i][0], dp[i][1]);
            dp[i+1][1] = max(dp[i][0], dp[i][2])+1;
        }
    }
    // cout << "R S P" << endl;
    // rep(i,1,n+1){
    //     rep(j,3){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}