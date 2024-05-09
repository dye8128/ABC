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

#define inf 1000000
ll h, w; 
vll dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vstr a;

bool in(ll x, ll h){
    return 0 <= x && x < h;
}

void dfs(vvll& g, ll x0, ll y0, ll x, ll y, vvll& seen, ll d, ll e){
    seen[x][y] = 1;

    rep(i,4){
        ll x1 = x + dx[i], y1 = y + dy[i];
        if(!(in(x1,h)&&in(y1,w))) continue;
        if(seen[x1][y1]) continue;
        if(a[x1][y1] == '#'){
            continue;
        }else{
            if(d <= e){
                g[x0*w+y0].emplace_back(x1*w+y1);
                dfs(g,x0,y0,x1,y1,seen,d+1,e);
            }
        }
    }
}

void bfs(vvll& g, ll x0, ll y0, ll e){
    vvll dist(h,vll(w,-1));
    queue<vll> que;

    dist[x0][y0] = 0;
    que.push({x0,y0});

    while(!que.empty()){
        auto v = que.front();
        que.pop();
        ll x = v[0], y = v[1];
        rep(i,4){
            ll x1 = x + dx[i], y1 = y + dy[i];
            if(!(in(x1,h)&&in(y1,w))) continue; 
            if(dist[x1][y1] != -1 || a[x1][y1] == '#') continue;
            dist[x1][y1] = dist[x][y] + 1;
            if(dist[x1][y1] <= e){
                g[x0*w+y0].emplace_back(x1*w+y1);
                que.push({x1,y1});
            }
        }
    }
}

vll seen2;
void dfs2(vvll &g, ll v){
    seen2[v] = 1;
    each(w,g[v]){
        if(seen2[w] == 1){
            continue;
        }
        dfs2(g,w);
    }
}

int main() {
    cin >> h >> w;
    a.resize(h);
    rep(i,h) cin >> a[i];
    ll n; cin >> n;
    vll r(n), c(n), e(n);
    rep(i,n){
        cin >> r[i] >> c[i] >> e[i];
        r[i]--;c[i]--;
    }
    
    vvll g(h*w,vll());
    rep(i,n){
        ll x = r[i], y = c[i], eg = e[i];
        vvll seen(h,vll(w,0));
        bfs(g,x,y,eg);
    }

    // rep(i,h*w){
    //     cout << i << ": ";
    //     each(vv,g[i]){
    //         cout << vv << " ";
    //     }
    //     cout << endl;
    // }

    ll s, t;
    rep(i,h){
        rep(j,w){
            if(a[i][j] == 'S'){
                s = i*w+j;
            }
            if(a[i][j] == 'T'){
                t = i*w+j;
            }
        }
    }
    seen2.resize(h*w,0);
    dfs2(g,s);

    cout << (seen2[t] == 1 ? "Yes" : "No") << endl;
}