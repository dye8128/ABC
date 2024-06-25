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
    str x_str; cin >> x_str;
    if(x_str.size() == 1){
        cout << !(x_str[0] == '0') << endl;
        return 0;
    }
    if(x_str.size() == 2 && x_str[0] == '-'){
        cout << 0 << endl;
        return 0;
    }
    ll i = x_str.size()-2;
    if(x_str.back() == '0'){
        rep(i, x_str.size()-1){
            cout << x_str[i];
        }
        cout << endl;
        return 0;
    }
    if(x_str[0] == '-'){
        // while(x_str[i] == '0'){
        //     x_str[i] = '9';
        //     i--;
        // }
    }else{
        if(x_str[i] != '9'){
            x_str[i]++;
        }else{
            while(x_str[i] == '9' && i>=0){
                x_str[i] = '0';
                i--;
            }
            if(x_str[0] == '0') cout << 1;
        }
    }
    rep(i, x_str.size() - 1){
        cout << x_str[i];
    }
    cout << endl;
}