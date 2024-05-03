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
    ll n; cin >> n;
    vll monster(n), ans;
    vll ts(n), xs(n);
    rep(i,n){
        cin >> ts[i] >> xs[i];
        xs[i]--;
    }
    rep(_,n){
        ll i = n - 1 -_;
        ll t, x;
        t = ts[i]; x = xs[i];
        if(t == 2){
            monster[x] ++;
        }
        if(t == 1){
            if(monster[x] > 0){
                ans.emplace_back(1);
                monster[x] --;
            }else{
                ans.emplace_back(0);
            }
        }
    }
    if(reduce(all(monster)) > 0){
        cout << -1 << endl;
        return 0; 
    }
    ll pos = 0, m = 0, ind = ans.size() - 1;
    rep(i,n){
        ll t = ts[i], x = xs[i];
        if(t == 2){
            pos--;
        }
        if(t == 1){
            if(ans[ind] == 1l){
                pos++;
                m = max(m, pos);
            }
            ind--;
        }
        // cout << pos <<" "<< ind << endl;
    }
    cout << m << endl;
    rep(i,ans.size()) cout << ans[ans.size() - 1 - i] << " "; cout << endl;
}