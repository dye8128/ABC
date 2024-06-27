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

ll h, w; 

bool in(ll x, ll y){
    return x >= 0 && x < h && y >= 0 && y < w;
}

int main() {
    cin >> h >> w;
    vstr s(h);
    rep(i,h) cin >> s[i];
    vll dx = {1,0,-1,0}, dy = {0,1,0,-1};
    vvll dist(h, vll(w,-1));
    vvll seen(h, vll(w,0));
    queue<pll> q;
    q.push({0,0}); seen[0][0] = 1; dist[0][0] = 1;
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        rep(i,4){
            if(in(x+dx[i],y+dy[i]) && !seen[x+dx[i]][y+dy[i]]){
                seen[x+dx[i]][y+dy[i]] = 1;
                if(s[x+dx[i]][y+dy[i]] == '.'){
                    dist[x+dx[i]][y+dy[i]] = dist[x][y] + 1;
                    q.push({x+dx[i],y+dy[i]});
                }
            }
        }
    }
    ll white = 0;
    rep(h) each(c,s[i]) white += (c == '.');

    cout << (dist[h-1][w-1] > 0 ? white - dist[h-1][w-1] : -1) << endl;
}