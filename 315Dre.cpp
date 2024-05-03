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
using vset = vector<set<int>>;

vvint c_int;
vector<multiset<int>> hcolors_m, wcolors_m;
vset hcolors, wcolors;
int h, w; 

void check() {
    auto wcolors_m_ = wcolors_m;
    auto wcolors_ = wcolors;
    bool flag = false;

    for(int i = 0; i < h; i++){
        if(hcolors.at(i).size() == 1){
            if(hcolors_m.at(i).size() >= 2){
                flag = true;
                auto itr = hcolors.at(i).begin();
                auto color = *itr;
                hcolors.at(i).clear();
                hcolors_m.at(i).clear();
                // cout << "h" << i << ":" << color << endl;
                for(int j = 0; j < w; j++){
                    auto itr2 = wcolors_m_.at(j).find(color);
                    wcolors_m_.at(j).erase(itr2);
                    if(wcolors_m_.at(j).count(color) == 0){
                        wcolors_.at(j).erase(color);
                    }
                }
            }
        }
    }

    for(int i = 0; i < w; i++){
        if(wcolors.at(i).size() == 1){
            if(wcolors_m.at(i).size() >= 2){
                flag = true;
                auto itr = wcolors.at(i).begin();
                auto color = *itr;
                wcolors_.at(i).clear();
                wcolors_m_.at(i).clear();
                // cout << "w" << i << ":" << color << endl;
                for(int j = 0; j < h; j++){
                    auto itr2 = hcolors_m.at(j).find(color);
                    if(itr2 != hcolors_m.at(j).end()){
                        hcolors_m.at(j).erase(itr2);
                        if(hcolors_m.at(j).count(color) == 0){
                            hcolors.at(j).erase(color);
                        }
                    }
                }
            }
        }
    }
    wcolors_m = wcolors_m_;
    wcolors = wcolors_;
    if(flag) check();
    return;
}

int main() {
    cin >> h >> w;
    c_int.resize(h,vint(w));
    hcolors.resize(h);
    hcolors_m.resize(h);
    wcolors.resize(w);
    wcolors_m.resize(w);
    vstr c(h);
    for(int i = 0; i < h; i++){
        cin >> c.at(i);
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char tmp = c.at(i).at(j);
            int color = int(tmp - 'a');
            c_int.at(i).at(j) = color;
            hcolors_m.at(i).insert(color);
            hcolors.at(i).insert(color);
            wcolors_m.at(j).insert(color);
            wcolors.at(j).insert(color);
        }
    }
    // cout << "inputed" << endl;
    check();
    int ans = 0;
    for(auto tmp: hcolors_m){
        ans += tmp.size();
    }
    cout << ans << endl;
}