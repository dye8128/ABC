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

bool in(ll i, ll n){
    return i >= 0 && i < n;
}

int main() {
    ll n; cin >> n;
    vstr row(n);
    rep(i, n) cin >> row[i];
    vll rowO(n), colO(n);
    // vll rowP(n), colP(n);
    // ll dob = 0;
    rep(i, n){
        rep(j, n){
            if(row[i][j] == 'o'){
                rowO[i] ++;
                colO[j] ++;
                // if(in(j + 1, n) && row[i][j+1] == 'o'){
                //     rowP[i]++;
                //     if(in(i + 1, n) && row[i + 1][j + 1] == 'o'){
                //         dob++;
                //     }
                //     if(in(i + 1, n) && row[i + 1][j] == 'o'){
                //         dob++;
                //     }
                //     if(in(i - 1, n) && row[i - 1][j + 1] == 'o'){
                //         dob++;
                //     }
                //     if(in(i - 1, n) && row[i - 1][j] == 'o'){
                //         dob++;
                //     }
                // }
                // if(in(i + 1, n) && row[i + 1][j] == 'o'){
                //     colP[i]++;
                // }
            }
        }
    }
    ll ans = 0;
    // ll rowS = 0, colS = 0;
    // rep(i,n){
    //     rowS+=rowO[i];
    //     colS+=colO[i];
    // }
    // cout << rowS << colS << dob << endl;
    rep(i,n){
        rep(j,n){
            if(row[i][j] == 'o'){
                ans += (rowO[i] - 1) * (colO[j] - 1);
            }
        }
    }
    cout << ans << endl;
}