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

#include <atcoder/modint>
using mint = atcoder::modint998244353;

int main() {
    ll n; cin >> n;
    vll a(n); rep(n) cin >> a[i];
    
    vvc<map<ll,mint>> dp(n, vc<map<ll,mint>>(n+1));
    rep(i,1,n){
        rep(j,i){
            dp[i][2][a[i]-a[j]]++;
        }
    }
    // cout << "ok" << endl;
    rep(k,3,n+1){
        rep(i,k-1,n){
            rep(j,i){
                each(x, dp[j][k-1]){
                    if(x.first+a[j]==a[i]){
                        dp[i][k][x.first]+=x.second;
                    }
                }
            }
        }
    }
    cout << n << " ";
    rep(i,2,n+1){
        mint sum = 0;
        rep(j,n){
            each(x, dp[j][i]){
                sum += x.second;
            }
        }
        cout << sum.val() << " ";
    }
    cout << endl;
}