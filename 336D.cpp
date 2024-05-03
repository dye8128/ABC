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

ll search(vll &a){
    ll n = a.size();
    ll ok = 1, ng = n;
    while(abs(ok-ng) > 0){
        ll m = (ok - ng)/2;
        bool flag = true;
        ll l = 0, r = 0;
        rep(i,n){
            if((n - i + a[i])/2 >= m){
                l++;
            }else{
                l = 0;
            }
        }
    }
}

int main() {
    ll n; cin >> n;
    vll a(n);
    rep(i,n) cin >> a[i];
    // ll rank = 1, M = 0;
    // rep(i, n/2 + 1){
    //     if(a[i] >= rank){
    //         rank++;
    //         cout << i << ":" << rank << endl;
    //         continue;
    //     }else{
    //         rank--;
    //         bool flag = true;
    //         rep(j, rank){
    //             if(a[i + j] < rank - j - 1){
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if(flag){
    //             M = max(M, rank);
    //         }
    //         rank = a[i] + 1;
    //     }
    // }
    // cout << M << endl;
    ll ans = n, M = (n + 1)/2;
    ll rank = 1;
    rep(i, M){
        
        ll tmp = (n - i + a[i])/2;
        cout << i << ":" << tmp << endl;
        ans = min(min(tmp, rank), ans);
        rank++;
    }
    rank = M;
    rep(i, M, n){
        
        ll tmp = (i + a[i] + 1)/2;
        cout << i << ":" << tmp << endl;
        ans = min(min(tmp, rank), ans);
    }
    cout << ans << endl;
}