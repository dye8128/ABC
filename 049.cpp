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
    str s; cin >> s;
    ll i = 0;
    while(i < s.size()){
        str t;
        rep(j,5){
            if(i + j < s.size()){
                t += s[i + j];
            }else{
                cout << "NO" << endl;
                return 0;
            }
        }
        if(t == "erase"){
            if(i + 5 < s.size() && s[i + 5] == 'r'){
                i += 6;
            }else{
                i += 5;
            }
        }else if(t == "dream"){
            if(i + 6 < s.size() && s[i + 5] == 'e' && s[i + 6] == 'r'){
                if(i + 7 == s.size()){
                    break;
                }else if(i + 7 < s.size() && s[i + 7] != 'a'){
                    i += 7;
                }else{
                    i += 5;
                }
            }else{
                i += 5;
            }
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}