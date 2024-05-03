#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vint = vector<int>;
using vll = vector<ll>;
using vstr = vector<str>;
using vbool = vector<bool>;
using vvint = vector<vint>;
using vvll = vector<vll>;

int main() {
    str s; cin >> s;
    for(int i = 0; i < s.size(); i++){
        char c = s.at(i);
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
            cout << c;
        }
    }
    cout << endl;
}