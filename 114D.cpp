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

int main() {
    ll n; cin >> n;
    vll isPrime(n+1, 1);
    isPrime[0] = isPrime[1] = 0;
    rep(i, 2, n+1) {
        if(isPrime[i] == 0) continue;
        ll j = 2;
        while(i*j <= n) {
            isPrime[i*j] = 0;
            j++;
        }
    }
    vll f;
    rep(i,1,n+1){
        if(!isPrime[i]) continue;
        ll cnt = 1, val = 0;
        while(n/pow(i,cnt) > 0){
            val += n/pow(i,cnt);
            cnt++;
        }
        f.push_back(val);
    }
    // each(v, f) cout << v << " ";
    ll nf = f.size();
    ll ans = 0;
    vll cf(100, 0);
    rep(i, nf){
        ll j = 0;
        while(f[i] >= j){
            cf[j]++;
            j++;
        }
    }
    ans += cf[74];
    ans += max(0ll, cf[24] * (cf[2]-1));
    ans += max(0ll, cf[14] * (cf[4]-1));
    ans += max(0ll, cf[4] * (cf[4]-1) * (cf[2]-2)/2);
    cout << ans << endl;
}