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

void yesno(bool flag){cout << (flag ? "Yes" : "No") << endl;}

int main() {
    ll n; cin >> n;
    vll t(n), f(n);
    rep(i, n){
        ll d;
        cin >> t[i] >> d;
        f[i] = t[i] + d;
    }
    ll time = 0, ans = 0;
    ll waiting = 0, end = 0;
    sort(t.begin(),t.end());reverse(t.begin(),t.end());
    sort(f.begin(),f.end());reverse(f.begin(),f.end());
    // while(!f.empty()){
    //     if(t.back() >= f.back()){
    //         if(f.back() == time){
    //             waiting--;
    //             if(waiting < 0) waiting = 0;
    //             f.pop_back();
    //         }else{
    //             ll period = f.back() - time;
    //             if(waiting <= period){
    //                 ans+=waiting;
    //                 waiting = 0;
    //             }else{
    //                 waiting-=(period+1);
    //                 ans+=period+1;
    //             }
    //             time = f.back();
    //             f.pop_back();
    //         }
    //     }else{
    //         waiting++;
    //         t.pop_back();
    //     }
    // }
    while(!f.empty()){
        while(time>=t.back()){
            waiting++;
            t.pop_back();
        }
        if(waiting > 0){
            waiting--;
            ans++;
            while(time>f.back()){
                if(f.size()>0) f.pop_back();
            }
            time++;
        }else{
            if(f.back() < t.back()){
                time = f.back();
                f.pop_back();
            }else{
                time = t.back();
            }
        }
    }
    cout << ans << endl;
}