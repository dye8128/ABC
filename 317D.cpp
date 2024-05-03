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
    ll n; cin >> n;
    vll x(n), y(n), z(n);
    rep(i,n) cin >> x[i] >> y[i] >> z[i];

    ll sumX = 0, sumY = 0, sumZ = 0;
    vll inc(n); vll win(n); ll sz = 0;
    rep(i,n){
        sumX += x[i];
        sumY += y[i];
        sumZ += z[i];
        win[i] = (x[i] - y[i] > 0);
        sz += (x[i] - y[i] > 0) * z[i];
        inc[i] = (y[i] > x[i] ? z[i] : 0ll);
    }

    vc<pair<vll,ll>> a(1e5+1,{vll(n,0),1e12});
    a[sz] = {win, 0};
    
    rep(i,1e5+1){
        rep(j,n){
            ll need = max((x[j] + y[j] + 1) / 2 - x[j],0ll);
            if(i - inc[j] >= 0 && !a[i - inc[j]].first[j] && a[i].second > a[i - inc[j]].second + need){
                a[i].first = a[i - inc[j]].first;
                a[i].first[j] = 1;
                a[i].second = a[i - inc[j]].second + need;
                // cout << i << " " << a[i].second << endl;
            }
        }
    }
    ll ans = 1e12;
    // rep(i,47,60) cout << a[i].first << " "; cout << endl;
    // rep(i,47,60) cout << a[i].second << " "; cout << endl;
    rep(i,sumZ/2+1,1e5+1){
        ans = min(ans, a[i].second);
    }
    cout << ans << endl;
}