#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using vc = vector<T>;
template<class T>using vvc = vc<vc<T>>;
template<class T>using vvvc = vc<vvc<T>>;
using vint = vc<int>;
using vll = vc<ll>;
using vstr = vc<str>;
using vpint = vc<pint>;
using vpll = vc<pll>;
using vbool = vc<bool>;
using vvint = vvc<int>;
using vvll = vvc<ll>;
using vvvll = vvvc<ll>;

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
    vll x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vvvll g_(2);
    rep(i, n){
        g_[(x[i] + y[i])%2].emplace_back(vll({x[i], y[i]}));
    }
    ll ans = 0;
    rep(k, 2){
        auto g = g_[k];
        vll a, b;
        each(v, g){
            ll vx = v[0], vy = v[1];
            // if((vx-vy)%2==-1){
            //     vy--;
            // }
            a.emplace_back((vx+vy)/2);
            b.emplace_back((vx-vy)/2);
        }
        ll m = a.size();
        map<ll, ll> asum, anum, bsum, bnum;
        rep(i, m){
            // a[i] += 1e8; b[i] += 1e8;
            asum[a[i]+1e8]+=a[i];
            anum[a[i]+1e8]++;
            bsum[b[i]+1e8]+=b[i];
            bnum[b[i]+1e8]++;
        }
        ll tmp = 0;
        each(v,asum){
            tmp += v.second;
            asum[v.first] = tmp;
        }
        tmp = 0;
        each(v,bsum){
            tmp += v.second;
            bsum[v.first] = tmp;
        }
        tmp = 0;
        each(v,anum){
            tmp += v.second;
            anum[v.first] = tmp;
        }
        tmp = 0;
        each(v,bnum){
            tmp += v.second;
            bnum[v.first] = tmp;
        }

        // each(v,asum) cout << v.first - 1e8 << " " << v.second << endl; cout << endl;
        // each(v,anum) cout << v.first - 1e8 << " " << v.second << endl; cout << endl;
        // each(v,bsum) cout << v.first - 1e8 << " " << v.second << endl; cout << endl;
        // each(v,bnum) cout << v.first - 1e8 << " " << v.second << endl; cout << endl;
        
        rep(i,m){
            ans += anum[a[i]+1e8] * a[i] - asum[a[i]+1e8];
            ans += asum.rbegin()->second - asum[a[i]+1e8] - a[i] * (anum.rbegin()->second - anum[a[i]+1e8]);
            ans += bnum[b[i]+1e8] * b[i] - bsum[b[i]+1e8];
            ans += bsum.rbegin()->second - bsum[b[i]+1e8] - b[i] * (bnum.rbegin()->second - bnum[b[i]+1e8]);
            // cout << ans << endl;
        }
    }
    cout << ans/2 << endl;
}