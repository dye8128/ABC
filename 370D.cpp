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
    ll h, w, q; cin >> h >> w >> q;
    vll r(q), c(q); rep(i,q) cin >> r[i] >> c[i];
    vc<set<ll>> row(h), col(w);
    rep(i,h)rep(j,w){
        row[i].insert(j);
        col[j].insert(i);
    }
    rep(i,h) row[i].insert(-1);
    rep(i,w) col[i].insert(-1);
    rep(i,q){
        r[i]--; c[i]--;
        // cout << r[i] << " " << c[i] << endl;
        set<ll>::iterator it;
        if(row[r[i]].empty()) goto col;
        if(row[r[i]].count(c[i])){ row[r[i]].erase(c[i]); goto col;}
        it = row[r[i]].lower_bound(c[i]);
        // cout << *it << endl;
        if(it != row[r[i]].end()) {col[*it].erase(r[i]); it = row[r[i]].erase(it);}
        it--;
        if(it != row[r[i]].begin() && *it != -1){col[*it].erase(r[i]);  row[r[i]].erase(it);}

        // rep(j,w){
        //     each(k,col[j]) cout << k << " "; cout << endl;
        // }
        col:;
        if(col[c[i]].empty()) continue;
        if(col[c[i]].count(r[i])){ col[c[i]].erase(r[i]); continue;}
        it = col[c[i]].lower_bound(r[i]);
        if(it != col[c[i]].end()) {row[*it].erase(c[i]); it = col[c[i]].erase(it);}
        it--;
        if(it != col[c[i]].begin() && *it != -1){row[*it].erase(c[i]); col[c[i]].erase(it);}
        // rep(j,h){
        //     each(k,row[j]) cout << k << " "; cout << endl;
        // }
    }
    ll ans = 0;
    rep(i,h) ans += row[i].size() - 1;
    cout << ans << endl;
}