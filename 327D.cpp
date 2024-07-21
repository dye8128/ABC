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
    ll n, m; cin >> n >> m;
    vll a(m); rep(m) cin >> a[i];
    vll b(m); rep(m) cin >> b[i];
    vvll g(n);
    rep(m) {
        g[a[i] - 1].push_back(b[i] - 1);
        g[b[i] - 1].push_back(a[i] - 1);
    }
    queue<ll> q;
    vll dist(n, -1);
    ll s = 0;
    while(s < n){
        q.push(s);
        dist[s] = 0;
        while(!q.empty()){
            ll v = q.front(); q.pop();
            each(i, g[v]){
                if(dist[i] == -1){
                    dist[i] = dist[v] + 1;
                    q.push(i);
                }else{
                    if((dist[v] - dist[i])%2==0) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
        while(s < n && dist[s] != -1) s++;
    }
    cout << "Yes" << endl;
}