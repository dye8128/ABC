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

int main() {
    ll a, b, c; cin >> a >> b >> c;
    ll pop_c = 0;
    ll i = 0;
    vll cv(61,0);
    while(c > 0){
        pop_c += c%2;
        cv[i] = c%2;
        i++;
        c/=2;
    }
    ll ones = (a+b-pop_c)/2;
    // cout << pop_c << endl;
    if(!(a+b>=pop_c && (a+b-pop_c)%2==0 && a >= ones && b >= ones)){
        cout << -1 << endl;
        return 0;
    }
    ll x = 0, y = 0;
    i = 0;

    // each(v,cv) cout << v; cout << endl;

    while(i<61){
        if(cv[i] == 0){
            if(ones > 0){
                ones--;
                x+=1L<<i;
                y+=1L<<i;
                a--;
                b--;
            }
        }else{
            if(a>=b){
                a--;
                x+=1L<<i;
            }else{
                b--;
                y+=1L<<i;
            }
        }
        if(a==0 && b==0){
            break;
        }
        // cout << (1<<i) << " ";
        // cout << i <<" "<< x << " " << y << endl;
        i++;
    }
    if(a*b>0){
        cout << -1 << endl;
        return 0;
    }
    // cout << a << b << endl;
    cout << x << " " << y << endl;
}