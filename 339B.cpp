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

ll modify(ll x, ll n){
    if(x >= n) return x - n;
    if(x < 0) return x + n;
    return x;
}

int main() {
    ll h, w, n; cin >> h >> w >> n;
    vll dy = {0, 1, 0, -1}, dx = {-1, 0, 1, 0};
    ll ind = 0;
    ll x = 0, y = 0;
    vstr a(h);
    rep(i, h){
        rep(j, w){
            a[i] += '.';
        }
    }
    rep(i, n){
        if(a[x][y] == '.'){
            a[x][y] = '#';
            ind = (ind + 1) % 4;
        }else{
            a[x][y] = '.';
            ind = (ind + 3) % 4;
        }
        x += dx[ind]; y += dy[ind];
        x = modify(x, h);
        y = modify(y, w);
        // rep(i, h){
        //     cout << a[i] << endl;
        // }cout << endl;
    }
    rep(i, h){
        cout << a[i] << endl;
    }
}