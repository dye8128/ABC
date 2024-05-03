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
    int n, m; cin >> n >> m;
    int p; cin >> p;
    int ans = 0;
    if(n - m >= 0) ans = (n - m) / p + 1;
    cout << ans << endl;
}