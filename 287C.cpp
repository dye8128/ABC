#include <bits/stdc++.h>
using namespace std;

vector<bool> seen;
vector<vector<int>> g;
int n, m, cnt = 0;

bool dfs(int v) {
    if(g.at(v).size() > 2) return false; 
    if(g.at(v).size() == 1) cnt++;
    //cout << v << " " << cnt << endl;
    for(auto nv: g.at(v)) {  
        if(seen.at(nv) == false) {
            seen.at(nv) = true;
            if(!dfs(nv)) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    seen.resize(n,false);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--;v--;
        g.at(u).emplace_back(v);
        g.at(v).emplace_back(u);
    }
    seen.at(0) = true;
    if(dfs(0) == false) {
        cout << "No" << endl;
        return 0;
    }
    //cout << cnt << endl;
    vector<bool> goal(n, true);
    bool flag = equal(seen.begin(), seen.end(), goal.begin(), goal.end());
    if(flag && cnt == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}