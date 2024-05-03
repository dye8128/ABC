#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long;
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

ll n, m, k, l;
ll gcd(ll n, ll m){
    if(n > m)swap(n,m);
    if(m%n==0)return n;
    return gcd(m%n, n);
}

bool calc(ll a, ll nm){
    ll tmp = a * nm ;
    // cout << tmp << ":" << tmp/n + tmp/m - 2 * (tmp/(n * m)) << endl;
    return tmp/n + tmp/m - 2 * (tmp/l) >= k;
}

bool calc2(ll a){
    return a/n+a/m-2*(a/l)==k;
}

ll binary(ll nm){
    ll ok = max(n, m) * k, ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng)/2;
        if(calc(mid, 1)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int main() {
    cin >> n >> m >> k;
    l = n * m / gcd(n,m);
    cout << binary(n) << endl;
}