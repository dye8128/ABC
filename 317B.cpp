#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vint = vector<int>;
using vll = vector<ll>;
using vstr = vector<str>;
using vpint = vector<pair<int, int>>;
using vbool = vector<bool>;
using vvint = vector<vint>;
using vvll = vector<vll>;

int main() {
    int n; cin >> n;
    vint a(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    int s = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > s + i){
            cout << a[i] - 1 << endl;
            return 0;
        }
    }
}