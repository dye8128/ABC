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

ll log2(ll n){
    ll ans = 0, cal = 1;
    while(cal <= n){
        ans ++;
        cal *= 2;
    }
    return ans - 1;
}

ll pow2(ll n){
    ll ans = 1;
    rep(i,n){
        ans*=2;
    }
    return ans;
}

ll ans;
set<pll> s;

void cal(ll l, ll r){
    if(l>=r-1){
        if(r-l==1){
            s.insert(make_pair(l, r));
            ans++;
        }
        return;
    }
    ans++;
    // ll n = r - l;
    // n = log2(n);

    // cout << n << endl;
    // ll n = 0;
    // while(l/pow2(n) < r/pow2(n)) n++;
    // n--;

    ll n = 0;
    while(1){
        ll tmp = (l-1)/pow2(n) + 1;
        if(l == 0) tmp = 0;
        // ll tmp = l/pow2(n);
        if((tmp +1) * pow2(n) > r){
            n--;
            break;
        }
        n++;
    }
    ll tmp = (l-1)/pow2(n)+1;
    if(l == 0) tmp = 0;
    // cout << n << " " << tmp << " " << l << " " << r <<  endl;
    ll l1 = tmp * pow2(n), r1 = (tmp+1) * pow2(n);
    s.insert(make_pair(l1, r1));

    // cout << l << " " << l1 << " " << r1 << " " << r << endl;
    cal(l,l1);
    cal(r1,r);
}

int main() {
    ll l, r; cin >> l >> r;
    ans = 0;
    // cout << log2(l) << log2(r);
    cal(l, r);
    cout << ans << endl;
    each(v, s){
        cout << v.first << " " <<  v.second << endl;
    }
}