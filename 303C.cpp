#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    vector<vector<int>> cure(m, vector<int>(3, 1));
    vector<int> exist(m, 1);
    vector<int> r = {0, 0};
    for(int i = 0; i < m; i++) {
        cin >> cure.at(i).at(0) >> cure.at(i).at(1);
    }
    for(int i = 0; i < n; i++) {
        h--;
        switch (s.at(i))
        {
        case 'R':
            r.at(0)++;
            break;
        case 'L':
            r.at(0)--;
            break;
        case 'U':
            r.at(1)++;
            break;
        case 'D':
            r.at(1)--;
            break;
        }
        if(h < 0) {
            cout << "No" << endl;
            return 0;
        }
        if(h < k) {
            for(int i = 0; i < m; i++) {
                if(r.at(0) == cure.at(i).at(0) && r.at(1) == cure.at(i).at(1) && exist.at(i) == 1) {
                    exist.at(i) = 0;
                    h = k;
                    break;
                }
            }
        }
    }
    cout << "Yes" << endl;
}