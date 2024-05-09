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

void yesno(bool flag){cout << (flag ? "Yes" : "No") << endl;}

multiset<ll> s;
void calc(ll &x, multiset<ll> &sq){
    sq.insert(x%10);
    x /= 10;
    if(x > 0) calc(x,sq);
    else{
        while(sq.size() < s.size()){
            sq.insert(0l);
        }
    }
}

int main() {
    int n; cin >> n;
    str s_str; cin >> s_str;
    ll zero = 0;
    rep(i,n) {
        ll tmp = s_str[i] - '0';
        s.insert(tmp);
        if(tmp == 0) zero ++;
    }
    ll min = 0;//sqrt(pow(10,n-1-zero));
    ll max = sqrt(pow(10,n));
    ll ans = 0;
    rep(i,min,max+1){
        ll tmp = i * i;
        multiset<ll> sq;
        calc(tmp,sq);
        // each(a,sq) cout << a;cout << endl;
        if(sq == s){
            ans ++;
            // cout << i << endl;
        }
    }
    cout << ans << endl;
}