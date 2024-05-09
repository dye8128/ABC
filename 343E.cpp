#include <bits/stdc++.h>
#include <atcoder>
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

bool in(vll v, vll v0){
    rep(i, 3){
        if(v[i] <= v0[i] && v0[i] <= v[0] + 7){

        }else{
            return false;
        }
    }
    return true;
}

ll cnt(vvll v, vll v0){
    ll n = v.size();
    ll ans = 0;
    rep(i,n){
        if(in(v[i], v0)) ans++;
    }
    return ans;
}

vll vg(3);
vll vs = {0, 343, 0, 0};
vvll tmp(6,vll(4));
bool f = false;

void cal(ll ind, vll v){
    vvll vv = {{v[0],v[1],v[2]},{v[3],v[4],v[5]}};
    vll vtmp = v;
    rep(i,8){
        rep(j,8){
            ll ind1 = ind + 1, ind2 = ind + 2;
            vtmp[(ind1)%3] = v[ind1] + i;
            vtmp[(ind2)%3] = v[ind2] + j;
            vtmp[(ind)%3] = v[ind];
            vs[cnt(vv,vtmp)]--;
            vtmp[(ind)%3] += 7;
            vs[cnt(vv,vtmp)]++;
        }
    }
    rep(i,3){
        if(vs[i+1] != vg[i]){
            break;
        }
        if(i == 2){
            cout << "Yes" << endl;
            rep(t, 6){
                cout << v[t] << " ";
            }
            cout << endl;
            f = true;
            return;
        }
    }
}

int main() {
    rep(i,3) cin >> vg[i];    
    rep(a2, 9){

        tmp[0] = vs;
        rep(b2, 9){
            rep(c2, 9){
                rep(a3, 9){
                    rep(b3, 9){
                        rep(c3, 9){
                            vll v = {a2,b2,c2,a3,b3,c3};
                            
                        }
                    }
                }
                rep(a3, a2, a2 + 9){
                    rep(b3, b2, b2 + 9){
                        rep(c3, c2, c2 + 9){
                            vll v = {a2,b2,c2,a3,b3,c3};
                        }
                    }
                }
            }
        }
        vs = tmp[0];
    }
}