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
    ll h, w, y; cin >> h >> w >> y;
    vvll a(h+2, vll(w+2));
    rep(h) rep(j, w) cin >> a[i+1][j+1];
    vvc<pll> sizumu(y+1);
    vvll checked(h+2, vll(w+2, 0));
    rep(i,h+2) checked[i][0] = checked[i][w+1] = 1;
    rep(i,w+2) checked[0][i] = checked[h+1][i] = 1;
    rep(i,1,h+1) if(a[i][1] <= y) {sizumu[a[i][1]].push_back({i,1}); checked[i][1] = 1;}
    rep(i,1,h+1) if(a[i][w] <= y) {sizumu[a[i][w]].push_back({i,w}); checked[i][w] = 1;}
    rep(i,2,w) if(a[1][i] <= y) {sizumu[a[1][i]].push_back({1,i}); checked[1][i] = 1;}
    rep(i,2,w) if(a[h][i] <= y) {sizumu[a[h][i]].push_back({h,i}); checked[h][i] = 1;}
    rep(i, 1, y + 1){
        vll dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        queue<pll> q; each(j, sizumu[i]) q.push(j);
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            rep(k, 4){
                ll nx = x + dx[k], ny = y + dy[k];
                if(a[nx][ny] > i){
                    if(checked[nx][ny] == 0 && a[nx][ny] <= y){
                        checked[nx][ny] = 1;
                        sizumu[a[nx][ny]].push_back({nx, ny});
                    }
                }else if(checked[nx][ny] == 0){
                    checked[nx][ny] = 1;
                    sizumu[i].push_back({nx, ny});
                    q.push({nx, ny});
                }
            }
        }
    }
    // rep(i, 1, y+1) {cout << i << endl; each(v, sizumu[i]) cout << v.first << " " << v.second << endl;}
    vll ans(y+1);
    rep(i, 1, y+1) ans[i] = sizumu[i].size();
    rep(i, 1, y) ans[i+1] += ans[i];
    rep(i, 1, y+1) cout << h*w - ans[i] << endl;
}