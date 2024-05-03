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

ll powll(ll n, ll a){
    ll ans = 1;
    rep(i, a){
        ans *= n;
    }
    return ans;
}

ll m = 0;

int main() {
    int n; cin >> n;
    while(n > powll(2,m)) m++;
    cout << max(m, 1ll) << endl;
    vvll a(n, vll(m));
    rep(i, n){
        ll n1 = i;
        rep(j, m){
            a[i][j] = n1%2;
            n1/=2;
        }
    }

    // rep(i,n){
    //     rep(j,m){
    //         cout<< a[i][j];
    //     }
    //     cout << endl;
    // }

    rep(i, m){
        ll k = 0;
        vll x;
        rep(j, n){
            if(a[j][i] == 1){
                x.emplace_back(j+1);
                k++;
            }
        }
        cout << k << " ";
        each(v, x){
            cout << v <<" ";
        }
        cout << endl;
    }
    str s; cin >> s;
    ll ans = 0;
    rep(i, m){
        if(s[i] == '1'){
            ans += powll(2,i);
        }
    }
    cout << ans + 1 << endl;
}