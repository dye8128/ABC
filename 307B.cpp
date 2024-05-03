#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool flag = false;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int len = (a.at(i).size() + a.at(j).size());
            string b;
            for(int k = 0; k < a.at(i).size(); k++ ){
                b.push_back(a.at(i).at(k));
            }
            for(int k = 0; k < a.at(j).size(); k++ ){
                b.push_back(a.at(j).at(k));
            }
            flag = true;
            for(int k = 0; k < len / 2; k++){
                if(b.at(k) != b.at(len - k - 1)){
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}