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
    ll h, w; cin >> h >> w;
    vvll a(h,vll(w)), b(h,vll(w));
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    rep(i,h){
        rep(j,w){
            cin >> b[i][j];
        }
    }
    vc<multiset<ll>> a_row(h), a_col(w), b_row(h), b_col(w);
    rep(i,h){
        rep(j,w){
            a_row[i].insert(a[i][j]);
            b_row[i].insert(b[i][j]);
        }
    }
    rep(i,w){
        rep(j,h){
            a_col[i].insert(a[j][i]);
            b_col[i].insert(b[j][i]);
        }
    }
    multiset<multiset<ll>> a_rows, b_rows, a_cols, b_cols;
    rep(i,h){
        a_rows.insert(a_row[i]);
        b_rows.insert(b_row[i]);
    }
    rep(i,w){
        a_cols.insert(a_col[i]);
        b_cols.insert(b_col[i]);
    }
    if(a_rows != b_rows || a_cols != b_cols){
        cout << -1 << endl;
        return 0;
    }
    // vll row_ind = {0,1,2,3,4}, col_ind = {0,1,2,3,4};
    ll ans = 0;
    rep(i,h){
        if(a_row[i] != b_row[i]){
            rep(j,i+1,h){
                // cout << i << j << endl;
                ans++;
                if(a_row[j] == b_row[i]){
                    rep(k,j-i){
                        // cout << "  " << j-k << endl;
                        a_row[j - k] = a_row[j-k-1];
                    }
                    a_row[i] = b_row[i];
                    // cout << "row" << i << j << endl;
                    break;
                }
            }
        }
    }
    // cout << ans << endl;
    rep(i,w){
        if(a_col[i] != b_col[i]){
            rep(j,i+1,w){
                ans++;
                if(a_col[j] == b_col[i]){
                    rep(k,j-i){
                        a_col[j-k] = a_col[j-k-1];
                    }
                    a_col[i] = b_col[i];
                    // cout << "col" << i << j << endl;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}