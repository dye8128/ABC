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
    ll h, w, k; cin >> h >> w >> k;
    vstr s(h);
    rep(i, h) cin >> s[i];
    // cout << "A" << endl;
    ll ans = 1e7;
    rep(i, h){
        ll flag = 0, dot = 0;
        rep(j, w){
            if(j - k >= 0 && s[i][j - k] == '.'){
                dot--;
            }else if(j - k >= 0 && s[i][j - k] == 'x'){
                flag--;
            }
            if(s[i][j]== '.'){
                dot++;
            }else if(s[i][j] == 'x'){
                flag++;
            }
            if(flag <= 0 && j >= k - 1){
                ans = min(ans, dot);
            }
            // cout << i << j << ":" << dot << flag << endl;
        }
    }
    rep(j, w){
        ll flag = 0, dot = 0;
        rep(i, h){
            if(i - k >= 0 && s[i - k][j] == '.'){
                dot--;
            }else if(i - k >= 0 && s[i - k][j] == 'x'){
                flag--;
            }
            if(s[i][j]== '.'){
                dot++;
            }else if(s[i][j] == 'x'){
                flag++;
            }
            if(flag <= 0 && i >= k - 1){
                ans = min(ans, dot);
            }
            // cout << i << j << ":" << dot << flag << endl;
        }
    }
    cout << (ans < 10e6 ? ans : -1) <<endl;
}