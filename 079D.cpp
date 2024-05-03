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

// ダイクストラ法
#define INF (1ll << 60)
struct Edge{
    ll to; ll cost;
};
using Graph = vvc<Edge>;
void Dijkstra(Graph& graph, vll& dists, ll s){
    priority_queue<pll, vc<pll>, greater<pll>> q;
    q.emplace((dists[s] = 0), s);

    while(!q.empty()){
        ll dist = q.top().first;
        ll from = q.top().second;
        q.pop();

        if(dists[from] < dist) continue;
        each(edge,graph[from]){
            ll d = dists[from] + edge.cost;

            if(d < dists[edge.to]){
                q.emplace((dists[edge.to] = d), edge.to);
            }
        }
    }
}

int main() {
    ll h, w; cin >> h >> w;
    vvll c(10,vll(10));
    rep(i,10){
        rep(j,10) cin >> c[i][j];
    }
    Graph g(10);
    rep(i,10){
        rep(j,10){
            g[i].emplace_back(Edge{j,c[i][j]});
        }
    }

    vvll a(h,vll(w));
    rep(i,h){
        rep(j,w) cin >> a[i][j];
    }
    vll to1(10);
    rep(i,10){
        vll dists(10,INF);
        Dijkstra(g,dists,i);
        to1[i] = dists[1];
    }
    ll ans = 0;
    rep(i,h){
        rep(j,w){
            if(a[i][j]==-1)continue;
            ans += to1[a[i][j]];
        }
    }
    cout << ans << endl;
}