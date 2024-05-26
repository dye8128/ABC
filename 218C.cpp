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

vstr kaiten(vstr &s){
    vstr s_ = s;
    ll n = s.size();
    rep(i,n){
        rep(j,n){
            s_[i][j] = s[n-1-j][i];
        }
    }
    return s_;
}

vstr yose(vstr &s){
    ll n = s.size();
    ll imin = n, jmin = n;
    rep(i,n){
        rep(j,n){
            if(s[i][j] == '#'){
                imin = min(imin, i);
                jmin = min(jmin, j);
            }
        }
    }
    vstr s_ = s;
    rep(i,n){
        rep(j,n){
            s_[i][j] = (i+imin < n && j+jmin < n ? s[i+imin][j+jmin] : '.');
        }
    }
    return s_;
}

int main() {
    ll n; cin >> n;
    vstr s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];
    t = yose(t);
    rep(i,4){
        s = yose(s);
        // each(vs,s){
        //     each(v,vs){
        //         cout << v;
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        if(s == t){
            cout << "Yes" << endl;
            return 0;
        }

        s = kaiten(s);
    }
    cout << "No" << endl;
}