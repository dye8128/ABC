#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(0));
    vector<int> ans(n + 1, 0);
    int a_ij;
    for(int i = 0; i < m; i++) {
        int c; cin >> c;
        for(int j = 0; j < c; j++) {
            cin >> a_ij;
            a.at(i).push_back(a_ij);
        }
    }
    int sum = 0;
    for(int s = 0; s < (1<<m); s++) {
        for(int i = 0; i < m; i++){
            if((s >> i) & 1){
                for(int j = 0; j < a.at(i).size(); j++){
                    ans.at(a.at(i).at(j)) = 1;
                }
            }
        }
        int check = 0;
        for(int i = 0; i < n + 1; i++){
            check+=ans.at(i);
            ans.at(i) = 0;
        }
        sum += (check == n);
    }
    cout << sum << endl;
}