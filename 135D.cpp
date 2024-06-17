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

using modint = atcoder::modint1000000007;

int main() {
    str s; cin >> s;
    ll n = s.size();
    reverse(all(s));
    vvc<modint> dp(n+1, vc<modint>(13, 0));
    vll mod(n); mod[0] = 1;
    rep(i, 1, n) mod[i] = (mod[i-1] * 10) % 13;
    if(s[0] == '?') rep(i, 10) dp[1][i] = 1;
    else dp[1][s[0]-'0'] = 1;
    rep(i, 1, n){
        auto c = s[i];
        if(c == '?'){
            rep(j, 10){
                ll j2 = mod[i] * j % 13;
                rep(k, 13) dp[i+1][(k+j2)%13] += dp[i][k];
            }
        }else{
            ll j = c - '0';
            ll j2 = mod[i] * j % 13;
            rep(k, 13) dp[i+1][(k+j2)%13] += dp[i][k];
        }
    }
    // rep(i,1,n+1){
    //   rep(j,13){
    //     cout << dp[i][j].val() << "\t";
    //   }
    //   cout << endl;
    // }
    cout << dp[n][5].val() << endl;
}