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
    ll n, q; cin >> n >> q;
    vll exist(n+1);
    vll a(n);
    rep(i,n){
        cin >> a[i];
        if(a[i]<=n) exist[a[i]]++;
    }
    set<ll> s;
    rep(i,n + 1){
        if(exist[i] == 0){
            s.insert(i);
        }
    }
    rep(_,q){
        ll i, x; cin >> i >> x;i--;
        exist[a[i]]--;
        if(exist[a[i]] == 0){
            s.insert(a[i]);
        }
        a[i] = x;
        if(x>n){
            cout << *s.begin() << endl;
            continue;
        }
        exist[x]++;
        if(exist[x] == 1){
            s.erase(x);
        }
        // rep(i,6)cout<<exist[i];cout<<endl;
        // if(mex > x){
        //     mex = x;
        // }else if(mex == x){
        //     rep(j,mex,2e5+1){
        //         if(exist[j] == 0){
        //             mex = j;
        //             break;
        //         }
        //     }
        // }
        cout << (*s.begin()) << endl;
    }
}