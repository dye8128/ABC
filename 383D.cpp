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

ll powll(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int main() {
    ll n; cin >> n;
    vll vec(2e6, 0);
    vll prime;
    rep(i,2,2e6){
        if(vec[i] == 0){
            prime.push_back(i);
            for(ll j = i; j < 2e6; j += i){
                vec[j] = 1;
            }
        }
    }
    ll ans = 0;
    ll m = prime.size();
    rep(i,m)rep(j,i+1,m){
        ll p1 = prime[i], p2 = prime[j];
        if(p1 > 2e3) break;
        if(p1*p1*p2*p2 > n) break;
        // printf("%lld\n", p1*p1*p2*p2);
        ans++;
    }
    rep(i,m){
        if(powll(prime[i],8) > n) break;
        // printf("%lld\n", powll(prime[i],8));
        ans++;
    }
    cout << ans << endl;
}