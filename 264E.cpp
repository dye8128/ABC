#include <bits/stdc++.h>
#include <atcoder/all>
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

using namespace atcoder;

int main() {
    ll n,m; cin >> n >> m;
    ll e; cin >> e;
    struct UV{
        ll u, v;
    };
    vc<UV> uv(e); rep(e) cin >> uv[i].u >> uv[i].v;
    ll q; cin >> q;
    vll x(q); rep(q) {cin >> x[i]; x[i]--;}
    vll ans(q);
    dsu s(n+m+1);
    rep(m){
        s.merge(n+i+1, 0);
    }
    vll sortedX = x;
    sort(all(sortedX));
    ll j = 0;
    rep(i,e){
        if(j < q && sortedX[j] == i){
            j++;
        }else{
            s.merge(uv[i].u, uv[i].v);
        }
    }
    rep(i,q){
        ans[i] = s.size(0) - 1;
        s.merge(uv[x[q-i-1]].u, uv[x[q-i-1]].v);
    }
    reverse(all(ans));
    each(v, ans) cout << v - m << endl;
}