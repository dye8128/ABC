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

int main() {
    int n; cin >> n;
    vvll d(n, vll(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > i){
                cin >> d[i][j];
            }else{
                d[i][j] = d[j][i];
            }
        }
    }
    for(auto tmp: d){
        for(auto v: tmp) cout << v << " ";
        cout << endl;
    }
}