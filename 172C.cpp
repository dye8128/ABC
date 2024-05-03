#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll binary_search(vll& a, ll b){
    ll ok = -1, ng = a.size(), m;
    while(abs(ok-ng)>1){
        m = (ok + ng)/2;
        a[m] <= b? ok = m: ng = m;
    }
    return ok;
}

int main() {
    ll n, m, k; cin >> n >> m >> k;
    vll a(n), b(m), suma(n + 1), sumb(m + 1);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        suma[i + 1] = a[i] + suma[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> b[i];
        sumb[i + 1] = b[i] + sumb[i];
    }
    ll ans = 0;
    for(ll i = 0; i < n + 1; i++){
        if(suma[i] <= k){
            ll read_b = binary_search(sumb, k - suma[i]);
            ll read = i + read_b;
            ans = max(ans, read);
        }
    }
    cout << ans << endl;
}