#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    int n, m; cin >> n >> m;
    vector<string> c(n);
    vector<string> d(m);
    vector<int> p(m);
    int p0;
    for(int i = 0; i < n; i++) {
        cin >> c.at(i);
    }
    for(int i = 0; i < m; i++) {
        cin >> d.at(i);
    }
    cin >> p0;
    for(int i = 0; i < m; i++) {
        cin >> p.at(i);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(c.at(i) == d.at(j)){
                ans += p.at(j) - p0;
                break;
            }
        }
        ans += p0;
    }
    cout << ans << endl;
}