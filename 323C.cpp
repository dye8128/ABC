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
    int n, m; cin >> n >> m;
    vint a(m);
    for(int i = 0; i < m; i++){
        cin >> a.at(i);
    }
    vstr s(n);
    for(int i = 0; i < n; i++){
        cin >> s.at(i);
    }
    vint score(n);
    rep(i,n){
        rep(j, m){
            char res = s[i][j];
            if(res == 'o'){
                score[i] += a[j];
            }
        }
        score[i] += i;
    }
    vint rank = score;
    sort(rank.begin(), rank.end());
    int tar = rank[n-1];
    rep(i,n){
        if(score[i] == tar){
            cout << 0 << endl;
        }else{
            vint getscore;
            rep(j,m){
                if(s[i][j] == 'x'){
                    getscore.emplace_back(a[j]);
                }
            }
            sort(getscore.begin(), getscore.end());
            reverse(getscore.begin(), getscore.end());
            // each(tmp, getscore) cout << tmp << " "; cout << endl;
            int ans = 0;
            while(score[i] < tar){
                score[i] += getscore[ans];
                ans++;
            }
            cout << ans << endl;
        }
    }
    
}