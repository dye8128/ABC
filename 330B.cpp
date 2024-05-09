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

ll search(ll a, ll l, ll r){
    ll c1, c2;
    while(l - r > 1){
        c1 = (l * 2 + r)/3;
        c2 = (l + 2 * r)/3;
        if(abs(c1 - a) < abs(c2 - a)){
            r = c1;
        }else{
            l = c2;
        }
    }
    return l;
}

int main() {
    ll n, l ,r; cin >> n >> l >> r;
    vll a(n);
    rep(i,n)cin >> a[i];
    rep(i,n){
        if(a[i] <= l){
            cout << l << " ";
        }else if(a[i] >= r){
            cout << r << " ";
        }else{
            cout << a[i] << " ";
        }
    }
}