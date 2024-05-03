#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<vector<int>> todo;
    vector<string> s(h);

    for(int i = 0; i < h; i++){
        cin >> s.at(i);
    }

    vector<vector<int>> S(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            switch(s[i][j]){
                case 's': S[i][j] = 0; break;
                case 'n': S[i][j] = 1; break;
                case 'u': S[i][j] = 2; break;
                case 'k': S[i][j] = 3; break;
                case 'e': S[i][j] = 4; break;
                default: S[i][j] = -1;
            }
        }
    }
    todo.push_back({0,0});
    if(S[0][0] == -1){
        cout << "No" << endl;
        return 0;
    }
    while(!todo.empty()){
        vector<int> v(2);
        v[0] = todo[todo.size() - 1][0];
        v[1] = todo[todo.size() - 1][1];
        todo.pop_back();
        if(seen[v[0]][v[1]]) continue;
        seen[v[0]][v[1]] = true;
        int i, j;
        i = v[0] + 1;
        j = v[1];
        if(i >= 0 && i < h && j >= 0 && j < w){
            if((S[v[0]][v[1]] + 1) % 5 == S[i][j]){
                if(!seen[i][j]) todo.push_back({i,j});
            }
        }
        i--; j = v[1] - 1;
        if(i >= 0 && i < h && j >= 0 && j < w){
            if((S[v[0]][v[1]] + 1) % 5 == S[i][j]){
                if(!seen[i][j]) todo.push_back({i,j});
            }
        }
        j += 2;
        if(i >= 0 && i < h && j >= 0 && j < w){
            if((S[v[0]][v[1]] + 1) % 5 == S[i][j]){
                if(!seen[i][j]) todo.push_back({i,j});
            }
        }
        i--; j = v[1];
        if(i >= 0 && i < h && j >= 0 && j < w){
            if((S[v[0]][v[1]] + 1) % 5 == S[i][j]){
                if(!seen[i][j]) todo.push_back({i,j});
            }
        }
    }
    if(seen[h-1][w-1]) cout <<"Yes" <<endl;
    else cout << "No" << endl;
}