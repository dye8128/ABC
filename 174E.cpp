#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll binary_search(vll& a, ll k){
    ll ok = 1e9, ng = 0, m, sum = 0;
    while(abs(ok-ng) > 1){
        sum = 0;
        m = (ok+ng)/2;
        for(auto v: a){
            sum += (v - 1) / m;
        }
        sum <= k ? ok = m: ng = m;
    }
    return ok;
}

int main() {
    ll n, k; cin >> n >> k;
    vll a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = binary_search(a, k);
    cout << ans << endl;
}