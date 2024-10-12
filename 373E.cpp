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
    ll n, k, m; cin >> n >> m >> k;
    if(n == m) m--;
    vll a(n); rep(i,n) cin >> a[i];
    vll idx(n); iota(all(idx), 0);
    sort(all(idx), [&](ll i, ll j){return a[i] > a[j];});
    ll Stop = 0;
    rep(m) Stop += a[idx[i]];
    set<ll> top_idx;
    rep(m) top_idx.insert(idx[i]);
    ll sum = 0;
    rep(n) sum += a[i];
    ll remain = k - sum;
    // cout << "remain: " << remain << endl;
    vll c(n);
    rep(n){
        ll s = Stop;
        if(top_idx.count(i)) {s -= a[i]; s += a[idx[m]];}
        ll ok = remain, ng = 0;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            ll lhs = (s + remain - mid) / m;
            ll rhs = mid + a[i];
            if(lhs <= rhs) ok = mid;
            else ng = mid;
        }
        c[i] = ok;
        if((s+remain)/m <= a[i]) c[i] = 0;
        if(a[idx[m-1]] > a[i]+remain) c[i] = -1;
    }
    rep(n) cout << c[i] << " "; cout << endl;
}