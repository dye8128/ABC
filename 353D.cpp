#include <bits/stdc++.h>
#include <atcoder/modint>
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

int main() {
    using modint = atcoder::static_modint<998244353>;
    ll n; cin >> n;
    vll a(n); rep(i,n) cin >> a[i];
    vll keta(n);
    // rep(i,n) keta[i] = log10(a[i] + 1) + 1;
    rep(i, n){
        ll k = 0, v = a[i];
        while(v >= 1){
            v /= 10;
            k++;
        }
        keta[i] = k;
    }
    vvll ketas(n, vll(11));
    vc<modint> sum(n);
    rep(i, n){
        sum[i] = a[i];
        if(i > 0){
            rep(j,1,11) ketas[i][j] = ketas[i - 1][j];
            sum[i] += sum[i - 1];
            // sum[i] %= 998244353;
        }
        ketas[i][keta[i]]++;
    }

    // rep(i,n){
    //     rep(j,1,11) cout << ketas[i][j] << " ";
    //     cout << endl;
    // }

    modint ans = 0;
    rep(i,n){
        modint mult = 0;
        rep(j,1,11){
            mult += (ketas[n-1][j] - ketas[i][j]) * ll(pow(10,j));
        }
        ans += a[i] * mult;
        ans += sum[n - 1] - sum[i];
        // ans %= 998244353;
    }
    // rep(i,1,n){
    //     ans += sum[i - 1] * ll(pow(10, keta[i]));
    //     // ans %= 998244353;
    //     ans += a[i] * i;
    //     // ans %= 998244353;
    // }
    cout << ans.val() << endl;
}