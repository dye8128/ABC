#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vint = vector<int>;
using vll = vector<ll>;
using vstr = vector<str>;
using vbool = vector<bool>;
using vvint = vector<vint>;
using vvll = vector<vll>;

int main() {
    int n; cin >> n;
    vvll s(n);
    for(int i = 0; i < n; i++){
        ll f, tmp;
        cin >> f >> tmp;
        f--;
        s.at(f).emplace_back(tmp);
    }
    ll max = 0, better = 0, best = 0, first = 0, second = 0;
    for(int i = 0; i < n; i++){
        better = 0; best = 0;
        if(s.at(i).size()>=2){
            for(auto a : s.at(i)){
                if(a >= best){
                    better = best;
                    best = a;
                }else if(a > better){
                    better = a;
                }
            }
        }else if(s.at(i).size() == 1){
            best = s.at(i).at(0);
        }
        if(best >= first){
            second = first;
            first = best;
        }else if(best > second){
            second = best;
        }
        if(max < best + better / 2){
            max = best + better / 2;
        }
    }
    if(max < first + second){
        max = first + second;
    }
    cout << max << endl;
}