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
    ll q; cin >> q;
    vll x, y;
    rep(i, n){
        x.emplace_back(n - i);
        y.emplace_back(0);
    }
    rep(i, q){
        ll j; cin >> j;
        if(j == 1){
            char c; cin >> c;
            if(c == 'R') {x.emplace_back(x.back()+1); y.emplace_back(y.back());}
            else if(c == 'L') {x.emplace_back(x.back()-1); y.emplace_back(y.back());}
            else if(c == 'U') {x.emplace_back(x.back()); y.emplace_back(y.back()+1);}
            else if(c == 'D') {x.emplace_back(x.back()); y.emplace_back(y.back()-1);}
        }
        if(j == 2){
            ll p; cin >> p;
            cout << x[x.size()-p] << " " << y[y.size()-p] << endl;
        }
    }
}