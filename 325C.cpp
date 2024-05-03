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

int h, w; vstr s;
vint dx8 = {-1,  0,  1,  1,  1,  0, -1, -1};
vint dy8 = {-1, -1, -1,  0,  1,  1,  1,  0};
vvint q(0, vint(2));
vint p = {0,0};
int ans = 0;

void dfs() {
    if(q.empty()){
        p[0]++;
        if(p[0] == h){
            p[0] = 0; p[1]++;
        }
        if(p[1] < w && s[p[0]][p[1]] == '#'){
            vint tmp = {p[0],p[1]};
            // cout << "p" << p[0] << p[1] << endl;
            q.emplace_back(tmp);
            ans++;
        }
        if(p[1] < w) dfs();
    }else{
        int x0 = q.back()[0], y0 = q.back()[1];
        // cout << x0 << y0 << endl;
        q.pop_back();
        s[x0][y0] = '.';
        rep(i,8){
            int x = x0 + dx8[i], y = y0 + dy8[i];
            if(x >= 0 && x < h && y >=0 && y < w && s[x][y] == '#'){
                vint tmp = {x,y};
                q.emplace_back(tmp);
            }
        }
        dfs();
    }
}

int main() {
    cin >> h >> w;
    rep(i,h){
        str tmp;
        cin >> tmp;
        s.emplace_back(tmp);
    }
    dfs();
    cout << ans << endl;
}