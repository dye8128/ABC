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
    vvint a(9,vint(9,0));
    rep(i,9){
        rep(j,9){
            cin >> a[i][j];
        }
    }
    set<int> b;
    bool flag = true;
    rep(i,9){
        b.clear();
        rep(j,9){
            b.insert(a[i][j]);
        }
        if(b.size() != 9){
            flag = false;
        }
    }
    rep(i,9){
        b.clear();
        rep(j,9){
            b.insert(a[j][i]);
        }
        if(b.size() != 9){
            flag = false;
        }
    }
    rep(x,3){
        rep(y,3){
            b.clear();
            rep(i,3){
                rep(j,3){
                    b.insert(a[3*x+i][3*y+j]);
                }
            }
            if(b.size()!=9){
                flag = false;
            }
        }
    }
    yesno(flag);
}