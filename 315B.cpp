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
    int m; cin >> m;
    int sum = 0;
    vint d(m);
    for(int i = 0; i < m; i++){
        cin >> d.at(i);
        sum += d.at(i);
    }
    int i = 0;
    int mid = sum / 2;
    while(mid >= d.at(i)){
        mid -= d.at(i);
        i++;
    }
    cout << i + 1 << " " << mid + 1 << endl;
}