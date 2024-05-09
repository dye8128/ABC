#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll binary_search(vll s, ll k){
    ll ok = s.size(), ng = -1, m;
    while (abs(ok - ng) > 1){
        m = (ok + ng)/2;
        s[m] >= k? ok = m: ng = m;
    }
    return ok;
}

int main() {
    ll n, k; cin >> n >> k;
    vll x(ll(1e5) + 1);
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        x[a] += b;
    }
    vll s(ll(1e5) + 1);
    for(ll i = 0; i < x.size() - 1; i++){
        s[i + 1] = s[i] + x[i + 1];
    }
    ll ans = binary_search(s, k);
    cout << ans << endl;
}