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

vvint a(3,vint(10,10000));

void calc(str s, int k){
    rep(i,s.size()){
        int num = s[i] - '0';
        if(a[k][num] == 10000){
            a[k][num] = i;
        }
    }
}

void setting(str &s){
    int m = s.size();
    char tmp = s[0];
    rep(i,1,m){
        s[i-1]=s[i];
    }
    s[m-1] = tmp;
}

vint stop(3,0);
vint sub(3,0);

void check(ll x, ll y, ll z){
    if(sub[x] == 1 && stop[y] + stop[z] == 1){
        stop[y] = 1;
        stop[z] = 1;
    }
}

int main(){
    int m; cin >> m;
    vstr s(3);
    rep(i,3)cin >> s[i];
    // setting(s1);setting(s2);setting(s3);
    // calc(s1,0);calc(s2,1);calc(s3,2);
    // cout << s1 << endl << s2 << endl << s3 << endl;
    int ans = 100000;
    int tmp;
    rep(i,10){
        tmp = 0;
        stop.assign(3,0);
        sub.assign(3,0);
        int sorou = 0;
        int stops = 0;
        while(stops < 3 && tmp <= m*3){
            vint x(3);
            int flag = 0;
            rep(j,3){
                x[j] = s[j][tmp%m] - '0';
                if(x[j] == i) flag ++;
            }
            // flag -= (tmp / m);
            if(flag <= 1){
                rep(j,3){
                    if(x[j] == i){
                        stop[j] = 1;
                    }
                }
            }else if(flag == 2){
                rep(j,3){
                    if(x[j] != i){
                        sub[j] = 1;
                    }
                }
            }else if(flag == 3){
                sorou ++;
            }
            rep(j,3){
                if(sub[j] == 1){
                    check(j,(j+1)%3,(j+2)%3);
                }
            }
            stops = 0;
            rep(j,3) stops+=stop[j];
            stops+=sorou;
            int subs = 0;
            rep(j,3){
                subs += sub[j];
            }
            if(stops + subs >= 3 && subs >= 2){
                stops = 3;
            }
            tmp++;
        }
        if(tmp == m*3 + 1) tmp = 100000;
        ans = min(ans, tmp - 1);
    }
    cout << (ans <= 300 ? ans : -1) << endl;
}