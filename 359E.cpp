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
    vll h(n); rep(n) cin >> h[i];
    vll ind(n);
    iota(all(ind), 0);
    sort(all(ind), [&](ll i, ll j){return h[i] < h[j];});
    reverse(all(ind));
    // each(i, ind) cout << i << " "; cout << endl;
    vll ans(n+1); ans[0] = 1;
    vll cols(n);
    set<ll> s;
    rep(n){
        if(s.empty()){
            s.insert(ind[i]);
            cols[ind[i]] = ind[i] + 1;
            continue;
        }
        ll m = *s.begin();
        // cout << m << endl;
        if(m > ind[i]){
            cols[ind[i]] = ind[i] + 1;
            s.insert(ind[i]);
        }else{
            auto it = s.lower_bound(ind[i]);
            if(it == s.begin()){
                // cout << "A" << endl;
                cols[ind[i]] = ind[i] + 1;
                s.insert(ind[i]);
                continue;
            }
            it--;
            cols[ind[i]] = ind[i] - (*it);
            s.insert(ind[i]);
        }
    }
    // rep(n) cout << cols[i] << " "; cout << endl;
    rep(n){
        ans[i+1] = cols[i] * h[i] + ans[i+1-cols[i]];
    }
    rep(n){
        cout << ans[i+1] << " ";
    }
    cout << endl;
}