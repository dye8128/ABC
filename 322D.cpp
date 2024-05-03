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

vc<vvint> p(3,vvint(4,vint(4,0)));
vc<vc<vvint>> pkaiten(3,vc<vvint>(4,vvint(4,vint(4,0))));
vc<vc<vc<vc<vvint>>>> pf(3,vc<vc<vc<vvint>>>(4,vc<vc<vvint>>(4,vc<vvint>(4,vvint(4,vint(4,0))))));
void kaiten(int ii){
    rep(k,4){
        rep(i,4){
            rep(j,4){
                if(k == 0){
                    pkaiten[ii][k][i][j] = p[ii][i][j];
                }else{
                    pkaiten[ii][k][i][j] = pkaiten[ii][k-1][j][3-i];
                }
            }
        }
    } 
}
void move(int i){
    rep(kaiten, 4){
        //左端と上端
        ll x0 = 5, y0 = 5;
        rep(j,4){
            rep(k,4){
                if(p[i][j][k] == 1){
                    x0 = min(x0, j); y0 = min(y0,k);
                }
            }
        }
        rep(dx,x0){
            rep(dy,y0){
                rep(j,4){
                    rep(k,4){
                        if(j+dx<4 && k + dy<4){
                            pf[i][dx][dy][kaiten][j][k] = pkaiten[i][kaiten][j+dx][k+dy];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    vc<vstr> tmp(3,vstr(4));
    vint size(3,0);
    rep(i,3){
        rep(j,4){
            cin >> tmp[i][j];
            rep(k,4){
                if(tmp[i][j][k] == '#'){
                    p[i][j][k] = 1;
                    size[i] ++;
                }
            }
        }
    }
    rep(i,3){
        kaiten(i);
    }
    bool flag;
    if(size[0] + size[1] + size[2] != 16){
        flag = false;
    }else{
        vll k(3,0);
        rep(i,3){
            move(i);
        }
        vvll d;
        rep(d0,4){
            rep(d1,4){
                rep(d2,4){
                    vll dtmp = {d0,d1,d2};
                    d.emplace_back(dtmp);
                }
            }
        }
        for(auto dx : d){
            for(auto dy :d){
                for(auto dk :d){
                    ll sum = 0;
                    rep(j,4){
                        rep(k,4){
                            ll _ = 0;
                            rep(i,3){
                                _ += pf[i][dx[i]][dy[i]][dk[i]][j][k];
                            }
                            sum += ll(_ > 0);
                        }
                    }
                    if(sum == 16) flag = true;
                }
            }
        }
    }
    yesno(flag);
}