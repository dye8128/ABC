#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vstr = vector<string>;

int main() {
    int n; cin >> n;
    vstr s(n);
    for(int i = 0; i < n; i++){
        cin >> s.at(i);
    }
    vstr s_inv = s;
    for(int i = 0; i < n; i++){
        reverse(s_inv.at(i).begin(), s_inv.at(i).end());
    }
    set<string> s_set, s_set_inv, intersect;
    for(auto str : s){
        s_set.insert(str);
    }
    for(auto str : s_inv){
        s_set_inv.insert(str);
    }
    int kaibun = 0;
    for(auto str : s_set){
        bool flag = true;
        for(int i = 0; i < str.size()/2; i++){
            if(str.at(i) != str.at(str.size() - 1 - i)){
                flag = false;
                break;
            }
        }
        if(flag) kaibun++;
    }
    set_intersection(s_set.begin(), s_set.end(), s_set_inv.begin(), s_set_inv.end(), inserter(intersect, intersect.begin()));
    int ans = s_set.size() - (intersect.size() - kaibun) / 2;
    cout << ans << endl;
}