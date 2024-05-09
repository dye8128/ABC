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
    int n, m;cin >> n >> m;
    str s, t;cin >> s >> t;
    int k = 0;
    map<char, int> mp;
    rep(i, m){
        mp.insert({t[i],i});
    }
    // each(v,mp)cout << v.second;
    rep(i, n){
        if(k < m && s[i] == t[k]){
            k++;
        }else if(s[i] == t[0]){
            k = 1;
        }else if(k == m){
            if(mp.count(s[i]) == 0){
                cout << "No" << endl;
                return 0;
            }else{
                k = mp[s[i]] + 1;
                cout << i << "A";
            }
        }else{
            cout << "No" << endl;
            return 0;
        }
        // cout << "A";
    }
    cout << (k == m ? "Yes" : "No") << endl;
}