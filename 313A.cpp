#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p.at(i);
    }
    int M = 0;
    for(int i = 1; i < n; i++){
        if(M < p.at(i)) M = p.at(i);
    }
    cout << max(0,M - p.at(0) + 1) << endl;
}