#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vint = vector<int>;

int main() {
    int n; cin >> n;
    int p, q; cin >> p >> q;
    vint d(n);
    int mini = 1000000;
    for(int i = 0; i < n; i++){
        cin >> d.at(i);
        mini = min(mini, d.at(i));
    }
    cout << min(p, q + mini) << endl;
}