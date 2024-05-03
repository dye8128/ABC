#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long int;

int main() {
    ll ans = 0;
    for(int i = 0; i < 64; i++){
        int a; cin >> a;
        ans += ll(a)<<i;
    }
    cout << ans << endl;
}