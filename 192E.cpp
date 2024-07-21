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
    ll n, m; cin >> n >> m;
    ll x, y; cin >> x >> y;
    x--; y--;

    struct Edge { ll to; ll k; ll t; };

    vvc<Edge> g(n);
    rep(m){
        ll a, b, t, k; cin >> a >> b >> t >> k;
        a--; b--;
        g[a].push_back({b, k, t});
        g[b].push_back({a, k, t});
    }

    vll dist(n, 1ll<<60);
    priority_queue<pll, vpll, greater<pll>> q;
    // dist, from
    q.push({0, x});
    dist[x] = 0;
    while(!q.empty()){
        auto [d, from] = q.top(); q.pop();
        if(dist[from] < d) continue;
        each(e, g[from]){
            ll to = e.to;
            ll k = e.k;
            ll t = e.t;
            ll wait = (dist[from] + k - 1) / k * k;
            if(dist[to] > wait + t){
                dist[to] = wait + t;
                q.push({dist[to], to});
            }
        }
    }
    cout << (dist[y] == (1ll<<60) ? -1 : dist[y]) << endl;
}