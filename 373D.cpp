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
    ll n, m; cin >> n >> m;
    vll u(m), v(m), w(m); rep(i,m) cin >> u[i] >> v[i] >> w[i];
    vc<vpll> g(n);
    rep(m){
        u[i]--; v[i]--;
        g[u[i]].push_back({v[i], w[i]});
        g[v[i]].push_back({u[i], -w[i]});
    }
    vll visited(n,0);
    pqueue pq;
    vll ans(n,0);
    ll s = 0;
    while(s < n){
        while(visited[s] == 1){
            s++;
        }
        if(s == n) break;
        pq.push(s);
        ll sumw = 0;
        while(!pq.empty()){
            ll now = pq.top(); pq.pop();
            if(visited[now] == 1) continue;
            visited[now] = 1;
            each(i,g[now]){
                // cout << now << " " << i.first << " " << i.second << endl;
                pq.push(i.first);
                ans[i.first] = ans[now] + i.second;
            }
        }
    }
    rep(n){
        cout << ans[i] << " ";
    }
    cout << endl;
}