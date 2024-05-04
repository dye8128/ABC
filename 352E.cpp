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

int main() {
    ll n; ll m; cin >> n >> m;
    vc<tuple<ll, ll, ll>> edges;
    
    rep(i,m){
        ll k, c; cin >> k >> c;
        vll a(k);
        rep(j,k){
            cin >> a[j];
            a[j]--;
        }
        rep(j,1,k){
            edges.emplace_back(c,a[0],a[j]);
        }
    }
    sort(all(edges));
    dsu uf(n);
    ll ans = 0;
    each(edge,edges){
        auto[c,u,v] = edge;
        if(!uf.same(u,v)){
            uf.merge(u,v);
            ans += c;
        }
    }
    cout << (uf.groups().size() == 1 ? ans : -1) << endl;
}