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
    ll n, m; cin >> n >> m;
    ll p; cin >> p;
    vll a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    vll b(m);
    for(int i = 0; i < m; i++){
        cin >> b.at(i);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    vll c(n); //pを超えない副菜の最大値
    vll a_sum(n),b_sum(m);
    rep(i,n){
        c[i] = p-a[i];
    }
    rep(i,m){
        if(i == 0){
            b_sum[0] = b[0];
        }else{
            b_sum[i] = b_sum[i-1] + b[i];
        }
    }
    // each(tmp,a) cout << tmp << " "; cout <<endl;
    // each(tmp,b) cout << tmp << " "; cout <<endl;
    // each(tmp,b_sum) cout << tmp << " "; cout <<endl; 
    ll j = 0;
    ll ans = 0;
    rep(i,n){
        if(j<0)j=0;
        while(j < m && c[i] >= b[j]){
            j++;
        }
        j--;
        ll tmp = 0;
        if(j>=0){
            tmp = a[i] * (j+1) + b_sum[j];
        }
        tmp += p * (m - 1 - j);
        // cout << i << " " << j << " " << tmp << endl;
        ans += tmp;
    }
    cout << ans << endl;
}