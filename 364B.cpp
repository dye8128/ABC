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
    ll h, w; cin >> h >> w;
    ll si, sj; cin >> si >> sj; si--; sj--;
    vstr c(h); each(i, c) cin >> i;
    str x; cin >> x;
    rep(x.size()){
        if(x[i] == 'L'){
            if(sj == 0) continue;
            if(c[si][sj-1] == '#') continue;
            sj--;
        }else if(x[i] == 'R'){
            if(sj == w-1) continue;
            if(c[si][sj+1] == '#') continue;
            sj++;
        }else if(x[i] == 'U'){
            if(si == 0) continue;
            if(c[si-1][sj] == '#') continue;
            si--;
        }else if(x[i] == 'D'){
            if(si == h-1) continue;
            if(c[si+1][sj] == '#') continue;
            si++;
        }
        // cout << si << " " << sj << endl;
    }
    cout << ++si << " " << ++sj << endl;
}