#include <bits/stdc++.h>
using namespace std;

vector<bool> seen1, seen2;
vector<int> len1, len2;
vector<vector<int>> g;

int MAX(vector<int> len){
    int max = 0;
    for(int i = 0; i < len.size(); i++){
        if(len.at(i) > max) max = len.at(i);
    }
    return max;
}

int bfs(vector<bool> seen, vector<int> len, int s, int offset){
    int i = 0;
    queue<int> todo, tmp;
    seen.at(s - offset) = true;
    todo.push(s);
    while(!todo.empty()){
        i++;
        tmp = todo;
        todo = {};
        while(!tmp.empty()){
            int v = tmp.front();
            tmp.pop();
            for(int u: g.at(v)){
                if(seen.at(u - offset) == false){
                    seen.at(u - offset) = true;
                    todo.push(u);
                    len.at(u - offset) = i;
                }
            }
        }
    }
    return MAX(len);
}

int main() {
    int n1, n2, m; cin >> n1 >> n2 >> m;
    g.resize(n1 + n2);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        g.at(u).emplace_back(v);
        g.at(v).emplace_back(u);
    }

    seen1.resize(n1, false);
    seen2.resize(n2, false);
    len1.resize(n1, 0);
    len2.resize(n2, 0);

    int max1 = bfs(seen1, len1, 0, 0);
    int max2 = bfs(seen2, len2, n1 + n2 - 1, n1);

    cout << max1 + max2 + 1 << endl;

}