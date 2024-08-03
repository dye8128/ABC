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

vll dec2bi(ll n){
    vll res;
    while(n > 0){
        res.push_back(n % 2);
        n /= 2;
    }
    return res;
}

int main() {
    ll n; cin >> n;
    vll a(n); each(i, a) cin >> i;
    vvll a_bi(n);
    rep(n) a_bi[i] = dec2bi(a[i]);
    ll m = 0;
    rep(n) m = max(m, (ll)a_bi[i].size());
    rep(n) a_bi[i].resize(m, 0);
    // rep(n){
    //     rep(j,m) cout << a_bi[i][m-1-j];
    //     cout << endl;
    // }

    vvll XOR(n, vll(m, 0));
    rep(n){
        rep(j,m){
            if(i == 0) XOR[i][j] = a_bi[i][j];
            else XOR[i][j] = XOR[i-1][j] ^ a_bi[i][j];
        }
    }
    // rep(n){
    //     rep(j,m) cout << XOR[i][m-1-j];
    //     cout << endl;
    // }
    vvll zeros(n, vll(m, 0));
    rep(n){
        rep(j,m){
            if(i == 0) zeros[i][j] = XOR[i][j] == 0;
            else zeros[i][j] = zeros[i-1][j] + (XOR[i][j] == 0);
        }
    }
    vll res(m, 0);
    rep(i,1,n){
        rep(j,m){
            if(i == 1) {res[j] += XOR[1][j]; continue;}
            if(XOR[i][j] == 1) res[j] += zeros[i-2][j];
            else res[j] += (i-1-zeros[i-2][j]);
            res[j] += XOR[i][j];
        }
    }
    // rep(m) cout << res[m-1-i] << " "; cout << endl;
    ll ans = 0;
    rep(j,m){
        ans += (1LL << j) * res[j];
    }
    cout << ans << endl;
}