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
    ll n, d; cin >> n >> d;
    vll x(n), y(n);
    rep(n) {cin >> x[i] >> y[i]; x[i] += 2e6; y[i] += 2e6;}
    sort(all(x)); sort(all(y));
    vll sumx(n+1, 0), sumy(n+1, 0);
    rep(n) sumx[i+1] = sumx[i] + x[i];
    rep(n) sumy[i+1] = sumy[i] + y[i];
    vll dx(4e6+1, 0), dy(4e6+1, 0);
    ll idx = 0;
    rep(i, 4e6+1){
        while(x[idx] < i && idx < n) idx++;
        dx[i] = sumx[n] - 2*sumx[idx] + (2*idx-n)*i;
    }
    idx = 0;
    rep(i, 4e6+1){
        while(y[idx] < i && idx < n) idx++;
        dy[i] = sumy[n] - 2*sumy[idx] + (2*idx-n)*i;
    }
    ll ans = 0;
    sort(all(dx)); sort(all(dy));
    idx = 4e6;
    rep(i, 4e6+1){
        while(idx >= 0 && dx[i] + dy[idx] > d) idx--;
        ans += idx+1;
    }
    cout << ans << endl;
}
