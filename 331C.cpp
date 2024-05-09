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
    vll a(n);
    rep(i, n) cin >> a[i];
    vll sort_a = a;
    sort(all(sort_a));
    reverse(all(sort_a));
    vll ind(n);
    iota(all(ind),0);

    sort(all(ind), [&a](size_t i1, size_t i2){
        return a[i1] > a[i2];
    });

    vll sum(n+1);
    ll tmp = 0, num = 0;
    rep(i, n+1){
        if(i == 0){
            sum[i] = 0;
            num = sort_a[i];
            tmp ++;
        }else{
            if(sort_a[i] < num){
                sum[i] = tmp * num + sum[i - 1];
                tmp = 1;
                num = sort_a[i];
            }else{
                tmp += 1;
                sum[i] = sum[i - 1];
            }
        }
    }
    // each(v, sort_a) cout << v << " "; cout << endl;
    // each(v, sum) cout << v << " "; cout << endl;
    // rep(i,n){
    //     cout << ind[i] << " ";
    //     cout << sum[ind[i] + 1] << " ";
    // }
    // cout << "A" << endl;
    vll ans(n);
    rep(i, n){
        ans[ind[i]] = sum[i];
    }
    rep(i, n) cout << ans[i] <<" ";
}