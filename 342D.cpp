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

ll cal(ll n, ll i){
    ll ans = 0;
    while(n % i == 0 && n > 0){
        ans ++;
        n /= i;
    }
    return ans;
}

int main() {
    // O(n * (2*10^5以下の素数の個数 = 17984))なので無理
    ll n; cin >> n;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    vll prime(200000, 1);
    rep(i, 3, 200000){
        rep(j, 2, sqrt(i) + 1){
            if(i % j == 0){
                prime[i] = 0;
                break;
            }
        }
    }
    // rep(i, 200){
    //     if(prime[i] == 1){
    //         cout << i << " ";
    //     }
    // }

    ll num0 = 0;
    rep(i, n){
        if(a[i] == 0){
            num0++;
        }
    }

    set<vll> aa;
    ll c = 0; // ループ回数
    aa.insert(a);
    rep(i, 2, 200000){
        if(prime[i] == 0){
            continue;
        }
        c++;
        set<vll> tmp = aa;
        each(vs, aa){
            tmp.erase(vs);
            vll a1, a2;
            each(v, vs){
                if(cal(v, i) % 2 == 0){
                    a1.emplace_back(v);
                }else{
                    a2.emplace_back(v);
                }
            }
            tmp.insert(a1);
            tmp.insert(a2);
        }
        aa = tmp;
        // each(v, aa){
        //     each(k, v){
        //         cout << k << " ";
        //     }cout << endl;
        // }
    }

    ll ans = 0;
    each(vs, aa){
        ll k = vs.size();
        ans += k * (k - 1) / 2;
    }
    ans += num0 * (n - num0);
    cout << ans << endl;
    cout << c << endl;
}