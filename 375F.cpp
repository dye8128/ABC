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

int main() {
    ll n, m, q; cin >> n >> m >> q;
    vll a(m), b(m), c(m); rep(m) cin >> a[i] >> b[i] >> c[i];
    vvll query(q);
    set<ll> eliminated;
    rep(q){
        ll qq; cin >> qq;
        if(qq == 1){
            ll x; cin >> x;
            query[i].push_back(x);
            eliminated.insert(x-1);
        }else{
            ll x, y; cin >> x >> y;
            query[i].push_back(x);
            query[i].push_back(y);
        }
    }

    vvll d(n, vll(n, 1e18));
    rep(m) {
        if(eliminated.count(i)) continue;
        d[a[i]-1][b[i]-1] = c[i];
        d[b[i]-1][a[i]-1] = c[i];
    }
    rep(n) d[i][i] = 0;
    rep(k,n) rep(i,n) rep(j,n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    // rep(n){rep(j,n) cout << (d[i][j] == 1e18 ? - 1 : d[i][j]) << "\t"; cout << endl;}
    vll ans;
    rep(qq,q){
        if(query[q-qq-1].size() == 1){
            ll k = query[q-qq-1][0];
            k--;
            ll x = a[k], y = b[k]; x--; y--;
            // cout << "k: " << k << " x: " << x << " y: " << y << endl;
            rep(i,n) rep(j,n) {d[i][j] = min(d[i][j], min(d[i][x] + c[k] + d[y][j], d[i][y] + c[k] + d[x][j]));}
            // cout << "q: " << q-qq << endl; rep(n){rep(j,n) cout << (d[i][j] == 1e18 ? - 1 : d[i][j]) << "\t"; cout << endl;}
        }else{
            ll x = query[q-qq-1][0], y = query[q-qq-1][1];
            x--; y--;
            ans.push_back(d[x][y] == 1e18 ? -1 : d[x][y]);
        }
    }
    reverse(all(ans));
    each(a, ans) cout << a << endl;
}