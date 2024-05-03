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
    vint cells(9);
    for(auto &&c : cells){
        cin >> c;
    }
    vvint rows = {{0,3,6},{1,4,7},{2,5,8},
                  {0,1,2},{3,4,5},{6,7,8},
                  {0,4,8},{2,4,6}};
    vint row = {0,1,2,3,4,5,6,7,8};
    int fit = 0, all = 0;
    do{
        all++;
        bool disappointed = false;
        for(auto tmp :rows){
            do{
                if(cells[tmp[0]] == cells[tmp[1]] && row[tmp[2]] > row[tmp[1]] && row[tmp[2]] > row[tmp[0]]){
                    disappointed = true;
                    break;
                }
            }while(next_permutation(tmp.begin(),tmp.end()));
        }
        if(!disappointed) fit++;
    }while(next_permutation(row.begin(),row.end()));
    double ans = (double)fit / all;
    cout << fixed;
    cout << setprecision(10) << ans << endl;
}