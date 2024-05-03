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

vvint c_int;
vvint hcolors, wcolors;
int h, w; 
pair<vint, vint> check(pair<vint, vint> hw){
    for(int tmp : hw.first) cout << tmp;
    cout << endl;
    for(int tmp : hw.second) cout << tmp;
    cout << endl;
    bool flag = false;
    vvint wcolors_ = wcolors;
    auto hw_ = hw;
    cout << "check" << endl;
    for(int i = 0; i < h; i++){
        vint deleted(26);
        if(hw.first.at(i) == 1){
            flag = true;
            int color = -1;
            for(int j = 0; j < 26; j++){
                int tmp = hcolors.at(i).at(j);
                if(tmp > 1){
                    color = j;
                    cout << color << endl;
                    break;
                }
            }
            if(color == -1){
                flag = false;
                break;
            }
            hw.first.at(i)--;
            hcolors.at(i).assign(26, 0);
            c_int.at(i).assign(w,27);
            for(int j = 0; j < w; j++){
                if(c_int.at(i).at(j) == color){
                    wcolors_.at(j).at(color)--;
                    if(!deleted.at(color)){
                        hw_.second.at(j)--;
                    }
                }
            }
            deleted.at(color) = 1;
        }
    }
    for(int i = 0; i < w; i++){
        if(hw.second.at(i) == 1){
            flag = true;
            int color = -1;
            for(auto tmp : wcolors.at(i)){
                if(tmp > 1){
                    color = i;
                    cout << color << endl;
                    break;
                }
            }
            if(color == -1){
                flag = false;
                break;
            }
            hw.second.at(i)--;
            wcolors_.at(i).assign(26, 0);
            for(int j = 0; j < h; j++){
                if(c_int.at(j).at(i) == color){
                    hcolors.at(j).at(color)--;
                    c_int.at(j).at(i) = 27;
                }
            }
        }
    }
    wcolors = wcolors_;
    hw = hw_;
    if(flag) check(hw);
    return hw;
}

int main() {
    cin >> h >> w;
    vstr c(h);
    // vector<vbool> exist(h, vbool(w, true));
    for(int i = 0; i < h; i++){
        cin >> c.at(i);
    }
    c_int.resize(h, vint(w));
    hcolors.resize(h, vint(26,0));
    wcolors.resize(w, vint(26,0));
    pair<vint, vint> hw({vint(h,0),vint(w,0)});
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int tmp = int(c.at(i).at(j) - 'a');
            c_int.at(i).at(j) = tmp;
            hcolors.at(i).at(tmp)++;
            wcolors.at(j).at(tmp)++;
            if(hcolors.at(i).at(tmp) == 1) hw.first.at(i)++;
            if(wcolors.at(j).at(tmp) == 1) hw.second.at(j)++;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << c_int.at(i).at(j);
        }
        cout << endl;
    }
    for(int i = 0; i < h; i++){
        for(auto tmp : hcolors.at(i)) cout << tmp;
        cout << endl;
    }
    for(int i = 0; i < w; i++){
        for(auto tmp : wcolors.at(i)) cout << tmp;
        cout << endl;
    }
    check(hw);
    vint hnum = hw.first, wnum = hw.second;
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(c_int.at(i).at(j) != 27) ans++;
        }
    }
    cout << ans << endl;
}