#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> fri(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> a.at(i).at(j);
    }
    for(int i = 0; i < m; i++ ) {
        for(int j = 0; j < n - 1; j++) {
            fri.at(a.at(i).at(j)).at(a.at(i).at(j + 1))++;
            fri.at(a.at(i).at(j + 1)).at(a.at(i).at(j))++;
        }
    }
    int sum = 0; 
    for(int i = 0; i < n + 1; i++) {
        int j = 0;
        while(j < i) {
            sum+=(fri.at(i).at(j) == 0);
            j++;
        }
    }
    cout << sum - n << endl;
}