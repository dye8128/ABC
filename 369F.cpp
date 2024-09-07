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
    ll h, w, n; cin >> h >> w >> n;
    vpll coins(n); rep(n) cin >> coins[i].first >> coins[i].second;
    sort(all(coins));
    vll idx;
    vll dp(n+1, 1e9);
    rep(n){
        auto it = upper_bound(all(dp), coins[i].second);
        idx.push_back(it - dp.begin());
        *it = coins[i].second;
    }
    // each(idx) cout << i << " "; cout << endl;
    vll lis;
    ll i = 0;
    ll m = 0;
    while(dp[i] != 1e9){
        m++;
        i++;
    }
    m--;
    i = n - 1;
    while(m >= 0){
        if(idx[i] == m){
            lis.push_back(i);
            m--;
        }
        i--;
    }
    reverse(all(lis));
    m = lis.size();
    // rep(m){
    //     cout << coins[lis[i]].first << " " << coins[lis[i]].second << endl;
    // }
    ll x = 1, y = 1;
    cout << m << endl;
    rep(i,m){
        rep(j, coins[lis[i]].first - x){
            cout << "D";
        }
        rep(j, coins[lis[i]].second - y){
            cout << "R";
        }
        x = coins[lis[i]].first;
        y = coins[lis[i]].second;
    }
    rep(h - x){
        cout << "D";
    }
    rep(w - y){
        cout << "R";
    }
    cout << endl;
}