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
    ll h, w; cin >> h >> w;
    pll s; cin >> s.first >> s.second;
    ll n; cin >> n;
    map<ll,vll> row, col;
    rep(n){
        ll x, y; cin >> x >> y;
        row[x].emplace_back(y);
        col[y].emplace_back(x);
    }
    each(pr,row){
        pr.second.emplace_back(0);
        pr.second.emplace_back(w+1);
    }
    each(pc,col){
        pc.second.emplace_back(0);
        pc.second.emplace_back(h+1);
    }
    each(pr,row) sort(all(pr.second));
    each(pc,col) sort(all(pc.second));
    // each(pr,row){
    //     auto r = pr.second;
    //     cout << pr.first << ": ";
    //     each(rr,r) cout << rr << " ";
    //     cout << endl;
    // }
    // each(pc,col){
    //     auto c = pc.second;
    //     cout << pc.first << ": ";
    //     each(cc,c) cout << cc << " ";
    //     cout << endl;
    // }

    ll q; cin >> q;
    rep(_,q){
        char d; cin >> d;
        ll l; cin >> l;
        ll x = s.first, y = s.second;
        if(d == 'L'){
            if(row.count(x) == 0) s.second = max(1ll, y - l);
            else {
                auto it = lower_bound(all(row[x]), y);
                if(*(--it) >= y - l) s.second = *it + 1;
                else s.second = y - l;
            }
        }else if(d == 'R'){
            if(row.count(x) == 0) s.second = min(w, y + l);
            else {
                auto it = lower_bound(all(row[x]), y);
                if(*it > y + l) s.second = y + l;
                else s.second = *it - 1;
            }
        }else if(d == 'U'){
            if(col.count(y) == 0) s.first = max(1ll, x - l);
            else {
                auto it = lower_bound(all(col[y]), x);
                if(*(--it) >= x - l) s.first = *it + 1;
                else s.first = x - l;
            }
        }else{
            if(col.count(y) == 0) s.first = min(h, x + l);
            else {
                auto it = lower_bound(all(col[y]), x);
                if(*it > x + l) s.first = x + l;
                else s.first = *it - 1;
            }
        }
        cout << s.first << " " << s.second << endl;
    }
}