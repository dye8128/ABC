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

vll yakusu;
void calc(vpll &soinsu, ll i, ll val){
    if(i == soinsu.size()){
        yakusu.push_back(val);
        return;
    }
    rep(_, soinsu[i].second+1){
        calc(soinsu, i+1, val);
        val *= soinsu[i].first;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll M = m;
    vpll soinsu;
    rep(i,2,sqrt(m)+1) {
        ll cnt = 0;
        while (m % i == 0) {
            m /= i;
            cnt++;
        }
        if(cnt > 0) soinsu.emplace_back(make_pair(i, cnt));
        if(m == 1) break;
    }
    if(m != 1) soinsu.emplace_back(make_pair(m, 1));
    // each(p, soinsu){
    //     cout << p.first << " " << p.second << endl;
    // }
    calc(soinsu, 0, 1);
    sort(all(yakusu));
    // each(i, yakusu){
    //     cout << i << endl;
    // }
    ll i = 0;
    while(i < yakusu.size() && yakusu[i] < n) i++;
    cout << M / yakusu[i] << endl;
}