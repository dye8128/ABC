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

bool is_in(ll x, ll y, ll h, ll w){
    return 0 <= x && x < h && 0 <= y && y < w;
}

int main() {
    ll h, w, x; cin >> h >> w >> x;
    ll p, q; cin >> p >> q;
    p--;q--;
    vvll s(h, vll(w));
    rep(h)rep(j, w) cin >> s[i][j];
    struct Node{
        ll s, x, y;
    };
    struct greater{
        bool operator()(const Node& a, const Node& b){
            return a.s > b.s;
        }
    };
    priority_queue<Node, vc<Node>, greater> pque;
    vint dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    ll size = s[p][q];
    vvll visited(h, vll(w));
    visited[p][q] = 1;
    pque.push({0, p, q});
    while(!pque.empty()){
        auto [enemy, p, q] = pque.top(); pque.pop();
        // printf("enemy: %lld p: %lld q: %lld\n", enemy, p, q);
        if(enemy >= (size + x - 1) / x) break;
        size += enemy;
        rep(4){
            ll nx = p + dx[i], ny = q + dy[i];
            if(is_in(nx, ny, h, w) && !visited[nx][ny]){
                visited[nx][ny] = 1;
                pque.push({s[nx][ny], nx, ny});
            }
        }
    }
    cout << size << endl;
}