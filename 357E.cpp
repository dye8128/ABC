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

int main(){
    ll n; cin >> n;
    vll a(n);
    vvll inv(n);
    dsu g(n);
    rep(n){
        cin >> a[i];
        a[i]--;
        inv[a[i]].emplace_back(i);
        g.merge(i, a[i]);
    }
    ll ans = 0;
    each(arr, g.groups()){
        if(arr.size() == 1){
            ans += 1;
            continue;
        }
        ll v = arr[0];
        vll seen(n,0);
        while(seen[v] == 0){
            seen[v] = 1;
            v = a[v];
        }
        ll v2 = a[v];
        ll cnt = 1;
        queue<ll> q; q.push(v2);
        vll dist(n,0); dist[v2] = 0;
        seen.assign(n,0); seen[v2] = 1;
        while(v2 != v){
            v2 = a[v2];
            cnt++;
            q.push(v2);
            dist[v2] = 0;
            seen[v2] = 1;
        }
        ans += cnt * q.size();
        // rep(j,n) if(seen[j]) cout << j+1 << " "; cout << endl;
        while(!q.empty()){
            ll u = q.front(); q.pop();
            each(j, inv[u]){
                if(!seen[j]){
                    seen[j] = 1;
                    dist[j] = dist[u] + 1;
                    ans += dist[j] + cnt;
                    q.push(j);
                }
            }
        }
    }
    cout << ans << endl;
}
