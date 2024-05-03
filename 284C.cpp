#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        g.at(u).emplace_back(v);
        g.at(v).emplace_back(u);
    }
    vector<bool> seen(n,false), connect(n, false), goal(n, true);
    stack<int> todo;
    int ans = 0;
    while(!equal(seen.begin(), seen.end(), goal.begin(), goal.end())) {
        for(int i = 0; i < n; i++) {
            if(seen.at(i) == false) {
                ans++;
                seen.at(i) = true;
                todo.push(i);
                while(!todo.empty()) {
                    int v = todo.top();
                    todo.pop();
                    for(int u: g.at(v)) {
                        if(seen.at(u) == false) {
                            seen.at(u) = true;
                            todo.push(u);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}