#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> s(8);
    for(int i = 0; i < 8; i++){
        cin >> s.at(i);
    }
    bool flag = true;
    for(int i = 0; i < 7; i++){
        if(s.at(i) > s.at(i + 1)) flag = false;
        if(s.at(i) < 100 || s.at(i) > 675) flag = false;
        if(s.at(i) % 25 != 0) flag = false;
        if(!flag) break;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}