#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> composition(set<pair<int, int>> R,set<pair<int, int>> S){
    set<pair<int, int>> SR;
    for(auto ab :R){
        int a = ab.first, b = ab.second;
        for(auto bc :S){
            int b_ = bc.first, c = bc.second;
            if(b == b_) SR.insert(make_pair(a,c));
        }
    }
    return SR;
}

set<pair<int, int>> transitiveClosure(set<pair<int, int>> R){
    set<pair<int, int>> R_plus = R, empty;
    vector<set<pair<int, int>>> R_vec = {R};
    int i = 0;
    while(1){
        R_vec.emplace_back(composition(R_vec[i],R));
        i++;
        set<pair<int, int>> tmp;
        set_union(R_plus.begin(),R_plus.end(),R_vec[i].begin(),R_vec[i].end(),inserter(tmp,tmp.begin()));
        if(R_plus == tmp) break;
        R_plus = tmp;
    }
    return R_plus;
}

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> ab;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ab.insert(make_pair(a, b));
    }
    auto ab_plus = transitiveClosure(ab);
    vector<int> win(n, 0);
    for(auto tmp : ab_plus){
        int a = tmp.first, b = tmp.second;
        win.at(a - 1)++;
        //cout << a << b << endl;
    }
    int flag = 0, ans;
    for(int i = 0; i < n; i++){
        if(win.at(i) == n - 1){
            flag++;
            ans = i + 1;
        }
    }
    if(flag == 1){
        cout << ans << endl;
    }else{
        cout << "-1\n";
    }
}