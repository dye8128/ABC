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
    ll n,m,k; cin >> n >> m >> k;
    vll c(m); str r;
    vvll a;
    rep(i,m){
        cin >> c[i];
        vll a_(c[i]);
        rep(j,c[i]){
            cin >> a_[j];
            a_[j]--;
        }
        a.emplace_back(a_);
        char r_; cin >> r_; r += r_;
    }
    ll ans = 0;
    rep(1<<n){
        vll b(n);
        ll t = 0;
        rep(j,n){
            b[j] = (i >> j) & 1;
            if(b[j] == 1) t++; 
        }
        bool flag = true;
        // each(v,b) cout << v; cout << endl;
        rep(j,m){
            ll tmp = 0;
            rep(k_,c[j]){
                if(b[a[j][k_]] == 1){
                    tmp++;
                }
            }
            if((tmp >= k && r[j] == 'x') || (tmp < k && r[j] == 'o')){
                flag = false;
                break;
            // }else{
            //     flag = false;
            //     // cout << "F" << endl;
            //     break;
            }
        }
        
        ans += flag;
    }
    cout << ans << endl;
}