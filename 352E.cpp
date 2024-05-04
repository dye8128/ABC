#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

vll seen;
void dfs(vc<map<ll,ll>> &g, ll v){
    seen[v] = 1;
    each(next,g[v]){
        if(!seen[next.first]){
            dfs(g,next.first);
        }
    }
}

int main() {
    ll inf = 1e10;
    ll n; ll m; cin >> n >> m;
    vc<map<ll,ll>> g(n);
    vc<tuple<ll,ll,ll>> edges;
    
    rep(i,m){
        ll k, c; cin >> k >> c;
        vll a(k);
        rep(j,k){
            cin >> a[j];
            a[j]--;
        }
        rep(j,k){
            rep(l,j+1,k){
                g[a[j]].insert({a[l],inf});
                g[a[l]].insert({a[j],inf});
                g[a[j]][a[l]] = min(g[a[j]][a[l]], c);
                g[a[l]][a[j]] = min(g[a[l]][a[j]], c);
            }
        }
    }
    // rep(i,n){
    //     each(v,g[i]) cout << v.first << " "; cout << endl;
    // }
    rep(i,m){
        each(v,g[i]){
            if(i < v.first){
                edges.emplace_back(tuple<ll,ll,ll>(v.second,i,v.first));
            }
        }
    }
    sort(all(edges));

    seen.assign(n,false);
    dfs(g,0);
    rep(i,n){
        if(!seen[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    
    dsu uf(n);
    ll ans = 0;

    each(e,edges){
        auto [c, i, j] = e;
        if(!uf.same(i,j)){
            uf.merge(i,j);
            ans += c;
        }
    }
    cout << ans << endl;
}