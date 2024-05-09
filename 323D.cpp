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

void yesno(bool flag){cout << (flag ? "Yes" : "No") << endl;}

ll ans = 0;
map<ll, ll> m;
// vll slim(10e7);
void calc(ll lev, ll num){
    m[lev] = num %= 2;
    lev *= 2;
    num /= 2;
    m[lev] += num;
    if(num > 0) calc(lev, num);
}

int main() {
    ll n; cin >> n;
    rep(i,n){
        ll s, c; cin >> s >> c;
        m.insert(make_pair(s,c));
    }
    // each(a,b,m){
    //     slim[a] = b; 
    // }
    each(a,b,m){
        calc(a, b);
    }
    each(a,b,m){
        ans += b;
        // cout << a << " " << b << endl;
    }
    cout << ans << endl;
}