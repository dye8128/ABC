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
    vint x(2e5+1, -1);
    int n, m; cin >> n >> m;
    vint a(m);
    for(int i = 0; i < m; i++){
        cin >> a.at(i);
    }
    vint b(m);
    for(int i = 0; i < m; i++){
        cin >> b.at(i);
    }
    x[b[0]] = 0;
    bool flag = true;
    ll i = 0;
    while(i <= a.size()){
        if(x[b[i]] == x[a[i]] && x[b[i]] != -1){
            flag = false;
        }
        if(x[b[i]] == -1){
            if(x[a[i]] == 0){
                x[b[i]] = 1;
            }else if(x[a[i]] == 1){
                x[b[i]] = 0;
            }else if(x[a[i]] == -1){
                a.emplace_back(a[i]);
                b.emplace_back(b[i]);
                continue;
            }
        }else if(x[b[i]] == 1){
            x[a[i]] = 0;
        }else if(x[b[i]] == 0){
            x[a[i]] = 1;
        }
        if(x[a[i]] == -1){
            if(x[b[i]] == 0){
                x[a[i]] = 1;
            }else{
                x[a[i]] = 0;
            }
        }else if(x[a[i]] == 1){
            x[b[i]] = 0;
        }else if(x[a[i]] == 0){
            x[b[i]] = 1;
        }
        i++;
    }
    yesno(flag);
    cout << a.size() << endl;
}