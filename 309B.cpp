#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < n; j++){
            a.at(i).at(j) = int(tmp.at(j) - '0');
        }
    }
    cout << a.at(1).at(0);
    for(int i = 0; i < n - 1; i++) cout << a.at(0).at(i);
    cout << endl;
    for(int i = 1; i < n - 1; i++) {
        cout << a.at(i + 1).at(0);
        for(int j = 1; j < n - 1; j++){
            cout << a.at(i).at(j);
        }
        cout << a.at(i - 1).at(n - 1) << endl;
    }
    for(int i = 0; i < n - 1; i++) cout << a.at(n - 1).at(i + 1);
    cout << a.at(n - 2).at(n - 1) << endl;
}