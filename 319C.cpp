#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vint = vector<int>;
using vll = vector<ll>;
using vstr = vector<str>;
using vpint = vector<pair<int, int>>;
using vbool = vector<bool>;
using vvint = vector<vint>;
using vvll = vector<vll>;

vint check;
vvint c(3, vint(3));
set<int> tmp;
vint v;
int dir = 0;

void cal(int i, int j) {
    tmp.insert(c[i][j]);
    v.emplace_back(c[i][j]);
}

void judge() {
    if(tmp.size() == 2){
        if(v[0] == v[1]){
            check[dir] = v[2];
        }else if(v[1] == v[2]){
            check[dir] = v[0];
        }else{
            check[dir] = v[1];
        }
    }else{
        check[dir] = -1;
    }
}

int main() {
    int n = 3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
        }
        dir++;
    }
    // double bunbo = 8 * 6;
    for(int i = 0; i < n; i++){
        tmp.clear();
        for(int j = 0; j < n; j++){
            cal(i, j);
        }
        dir++;
    }
    for(int i = 0; i < n; i++){
        tmp.clear();
        for(int j = 0; j < n; j++){
            cal(j, i);
        }
        dir++;
    }
    tmp.clear();
    for(int i = 0; i < n; i++){
        cal(i, i);
    }
    dir++;
    tmp.clear();
    for(int i = 0; i < n; i++){
        cal(i, 2-i);
    }
    double ans;
    cout << fixed;
    cout << setprecision(10) << ans << endl;
}