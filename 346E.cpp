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
    struct Color{
        ll color;
        ll i;
    };
    ll h, w, m; cin >> h >> w >> m;
    map<ll, ll> colors;
    vll t(m), a(m), x(m);
    rep(i,m){
        cin >> t[i] >> a[i] >> x[i];
    }
    map<ll, Color> Hcolor, Wcolor;
    rep(i,m){
        if(t[i] == 1){
            Hcolor.erase(a[i]);
            Hcolor.emplace(a[i],Color{x[i],i});
        }else{
            Wcolor.erase(a[i]);
            Wcolor.emplace(a[i],Color{x[i],i});
        }
    }

    // each(v,Hcolor){
    //     cout << v.first << " " << v.second.color << endl;
    // }cout << endl;
    // each(v,Wcolor){
    //     cout << v.first << " " << v.second.color << endl;
    // }

    colors.emplace(0,h*w-Hcolor.size()*w-Wcolor.size()*h);
    each(v,Hcolor){
        if(colors.count(v.second.color)==1){
            colors[v.second.color] += w;
        }else{
            colors.emplace(v.second.color,w);
        }
    }
    each(v,Wcolor){
        if(colors.count(v.second.color)==1){
            colors[v.second.color] += h;
        }else{
            colors.emplace(v.second.color,h);
        }
    }

    // cout << endl;
    // each(v,colors){
    //     cout << v.first << " " << v.second << endl;
    // }cout << endl;

    each(v1,Hcolor){
        each(v2,Wcolor){
            colors[0]++;
            if(v1.second.i > v2.second.i){
                colors[v2.second.color]--;
            }else{
                colors[v1.second.color]--;
            }
        }
    }
    auto tmp = colors;
    each(v,colors){
        if(colors[v.first] <= 0){
            tmp.erase(v.first);
        }
    }
    colors = tmp;
    cout << colors.size() << endl;
    each(v,colors){
        cout << v.first << " " << v.second << endl;
    }
}