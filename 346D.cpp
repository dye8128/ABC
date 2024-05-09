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
    str s; cin >> s;
    vll sum01(n,0), sum10(n,0);
    vll c(n);
    rep(i,n){
        cin >> c[i];
    }
    if(s[0]=='0'){
        sum10[0] = c[0];
    }else{
        sum01[0] = c[0];
    }
    rep(i,1,n){
        if(i%2==0){
            if(s[i] == '1'){
                sum10[i] = sum10[i-1];
                sum01[i] = sum01[i-1]+c[i];
            }else{
                sum01[i] = sum01[i-1];
                sum10[i] = sum10[i-1]+c[i];
            }
        }else{
            if(s[i] == '0'){
                sum10[i] = sum10[i-1];
                sum01[i] = sum01[i-1]+c[i];
            }else{
                sum01[i] = sum01[i-1];
                sum10[i] = sum10[i-1]+c[i];
            }
        }
    }
    ll ans = 1e15;
    rep(i,n-1){
        // cout << i << " " << sum10[i]+sum01[n-1]-sum01[i] << " " << sum01[i]+sum10[n-1]-sum10[i] << endl;
        ans = min(sum10[i]+sum01[n-1]-sum01[i],ans);
        ans = min(sum01[i]+sum10[n-1]-sum10[i],ans);
    }
    cout << ans << endl;
}