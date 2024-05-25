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
    ll n, t; cin >> n >> t;
    set<ll> x1, x2;
    // vll row(n);
    // rep(i,n){
    //     iota(all(row),n*i+1);
    //     bingo.emplace_back(row);
    // }
    // rep(i,n){
    //     vll col;
    //     rep(j,n){
    //         col.emplace_back(n*i+j+1);
    //     }
    //     bingo.emplace_back(col);
    // }
    // rep(i,n){

    // }
    // each(v,row) cout << v << endl;
    rep(i,n){
        x1.insert(n*i + i + 1);
        x2.insert(n*i + n - i);
    }
    vll a(t);
    rep(i,t) cin >> a[i];
    vll col(n), row(n);
    ll x1n = 0, x2n = 0;
    rep(I, t){
        ll i = (a[I] - 1)/n, j = a[I] % n - 1;
        if(j < 0) j += n;
        row[i] += 1; col[j] += 1;
        // cout << i << j << endl;
        if(x1.count(a[I]) == 1) x1n ++;
        if(x2.count(a[I]) == 1) x2n ++;
        if(row[i] == n || col[j] == n || x1n == n || x2n == n){
            cout << I+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}