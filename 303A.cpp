#include <bits/stdc++.h>
using namespace std;

int judge(string s, string t, int i ,char a, char b) {
    if(s.at(i) == a) {
        if(t.at(i) == b) return 0;
    }
    if(s.at(i) == b) {
        if(t.at(i) == a) return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int j = 0;
    for(int i = 0; i < n; i++) {
        int flag = 0;
        flag+=judge(s, t, i, '0', 'o');
        flag+=judge(s, t, i, 'l', '1');
        if(s.at(i) != t.at(i) ) flag++;
        if(flag == 3) {
            //cout << "wrong:" << i ;
            j = 1;
        }
    }
    if(j == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}