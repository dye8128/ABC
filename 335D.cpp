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

ll n;
bool in(ll x){
    return x >= 0 && x < n;
}

int main() {
    vll dx = {1, 0 ,-1, 0}, dy = {0, 1, 0, -1};
    cin >> n;
    vvll map(n, vll(n, -1));
    ll ind = 0, x = 0, y = 0;
    map[0][0] = 1;
    rep(i, 1, n * n - 1){
        if(in(x + dx[ind]) && in(y + dy[ind]) && map[x + dx[ind]][y + dy[ind]] == -1){
            
        }else{
            ind = (ind + 1)%4;
        }
        // cout << x << y << endl;
        x += dx[ind]; y += dy[ind];
        map[x][y] = i + 1;
    }
    rep(i,n){
        rep(j, n){
            if(map[i][j] == -1){
                cout << "T ";
            }else{
                cout << map[i][j] << " ";
            }
        }
        cout << endl;
    } 
}