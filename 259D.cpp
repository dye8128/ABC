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

ll d2(ll x1, ll y1, ll x2, ll y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

vll seen;

void dfs(vvll& g, ll v){
    seen[v] = 1;

    each(next, g[v]){
        if(seen[next] == 0){
            dfs(g, next);
        }
    }
}

int main() {
    ll n, sx, sy, tx, ty;
    cin >> n >> sx >> sy >> tx >> ty;
    vll x(n+2), y(n+2), r(n+2);
    rep(i,1,n+1) cin >> x[i] >> y[i] >> r[i];
    
    // S,Tには半径0の円があると見なす
    x[0] = sx; y[0] = sy; r[0] = 0;
    x[n+1] = tx; y[n+1] = ty; r[n+1] = 0;

    //グラフ作る
    vvll g(n+2);
    rep(i,n+2){
        rep(j,i+1,n+2){
            ll rr = (r[i] + r[j]) * (r[i] + r[j]);
            ll rr2 = (r[i] - r[j]) * (r[i] - r[j]);
            ll dd = d2(x[i],y[i],x[j],y[j]);
            if(rr >= dd && rr2 <= dd){
                g[i].emplace_back(j);
                g[j].emplace_back(i);
            }
        }
    }

    seen.resize(n+2,0);
    dfs(g,0);
    yesno(seen[n+1]);
}