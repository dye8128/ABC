#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
        c[i]--;
    }
    vector<vector<char>> a(m, vector<char>());
    for(int i = 0; i < n; i++){
        a[c[i]].emplace_back(s[i]);
    }
    vector<bool> first(m, true);
    vector<int> num(m, 0);
    for(int i = 0; i < n; i++){
        if(first[c[i]]){
            first[c[i]] = false;
            cout << a[c[i]][a[c[i]].size()-1];
        }else{
            cout << a[c[i]][num[c[i]]];
            num[c[i]]++;
        }
    }
    cout << endl;
}