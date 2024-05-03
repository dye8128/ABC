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

vll a;
vll r;

bool judge(ll n, ll m){
    r.assign(n,0);
    r[0] = m;
    rep(i,n-1){
        r[i+1] = 2 * a[i] - r[i];
    }
    ll r0 = 2 * a[n-1] - r[n-1];
    return r0 <= r[0];
}

int main() {
    ll n; cin >> n;
    rep(i,n){
        ll v; cin >> v;
        a.emplace_back(v);
    }

    // 二分探索
    ll ng = -1, ok = 1e10;
    while(abs(ok - ng)>1){
        ll m = (ok + ng) / 2;
        judge(n, m) ? ok = m : ng = m;
    }

    rep(i,n) cout << r[i] << " "; cout << endl;
}