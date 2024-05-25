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
using tll = tuple<ll,ll,ll>;

vll toBinary(ll n){
    vll a;
    while(n > 0){
        a.emplace_back(n%2);
        n/=2;
    }
    return a;
}

map<pll,vc<tll>> mp;
void func(ll l, ll r){
    if(mp.count(make_pair(l,r)) == 1) return;
    if(l > r){
        mp[make_pair(l,r)];
        return;
    }
    auto l2 = toBinary(l), r2 = toBinary(r);
    ll i = 0;
    while(l2[i] == r2[i]) i++;
    ll j = (l - 1) / pow(2,i) + 1;
    func(l,pow(2,i)*j-1);
    func(pow(2,i)*j,pow(2,i)*(j+1));
    func(pow(2,i)*(j+1)+1,r);
    vc<tll> t1;
    merge(all(mp[make_pair(l,pow(2,i)*j-1)]),all(mp[make_pair(pow(2,i)*j,pow(2,i)*(j+1))]),back_inserter(t1));
    t1.insert(t1.end(),all(mp[make_pair(pow(2,i)*(j+1)+1,r)]));
}


int main() {
    ll n, l, r; cin >> n >> l >> r;
}