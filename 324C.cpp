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

int main() {
    int n; cin >> n;
    str t; cin >> t;
    vstr s(n);
    for(int i = 0; i < n; i++){
        cin >> s.at(i);
    }
    vint ans;
    vbool f(4,true);
    rep(i,n){
        f = {1,1,1,1};
        str targ = s[i];
        ll len = targ.size();
        rep(j,len){
            if(t.size() != len){
                f[0] = 0;
                break;
            }
            if(targ[j]!=t[j]){
                f[0] = 0;
                break;
            }
        }
        bool flag = false;
        rep(j,len){
            if(t.size() != len + 1){
                f[1] = 0;
                break;
            }
            if(targ[j]!=t[j+flag]){
                if(!flag){
                    flag = 1;
                    j--;
                }
                else{
                    f[1] = 0;
                    break;
                }
            }
        }
        flag = false;
        rep(j,len){
            if(t.size() != len - 1){
                f[2] = 0;
                break;
            }
            if(targ[j]!=t[j-flag]){
                if(!flag){
                    flag = 1;
                }
                else{
                    f[2] = 0;
                    break;
                }
            }
        }
        flag = false;
        rep(j,len){
            if(t.size() != len){
                f[3] = 0;
                break;
            }
            if(targ[j]!=t[j]){
                if(!flag) flag = 1;
                else{
                    f[3] = 0;
                    break;
                }
            }
        }
        int judge = 0;
        rep(j,4) judge += f[j];
        if(judge) ans.emplace_back(i+1);
    }
    cout << ans.size() << endl;
    each(a,ans) cout << a << " ";cout << endl;
}