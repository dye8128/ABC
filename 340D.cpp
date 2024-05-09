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

ll INF = (1ll << 60);

struct Edge{
    ll to; ll cost;
};

using Graph = vvc<Edge>;

void Dijkstra(Graph &graph, vll& distances, ll ind){
    priority_queue<pll, vc<pll>, greater<pll>> q;
    q.emplace((distances[ind] = 0), ind);

    while(!q.empty())
    {
        ll distance = q.top().first;
        ll from = q.top().second;
        q.pop();

        if(distances[from] < distance) continue;

        each(edge, graph[from]){
            ll d = (distances[from] + edge.cost);

            if( d < distances[edge.to]){
                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
}

int main() {
    ll n; cin >> n;
    Graph graph(n + 1);
    rep(i, 1, n){
        ll a, b, x; cin >> a >> b >> x;
        graph[i].push_back({x, b});
        graph[i].push_back({i + 1, a});
    }
    
    vll distances(n + 1, INF);
    Dijkstra(graph, distances, 1);
    cout << distances[n] << endl;
    // rep(i, 1, n + 1)cout << distances[i] << " "; cout << endl;
}