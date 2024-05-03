#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll binary_search(vll &a, ll t){
    ll ok = a.size(), ng = -1, m;
    while(abs(ok - ng) > 1){
        m = (ok + ng)/2;
        a[m] >= t? ok = m: ng = m;
    }
    return ok;
}

int main() {
    ll n, m; cin >> n >> m;
    ll x, y; cin >> x >> y;
    vll a(n), b(m);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> b[i];
    }
    ll ans = 0, t = 0, k;
    while(1){
        // A -> B
        k = binary_search(a, t);
        if(k == n){
            break;
        }else{
            t = a[k] + x;
        }
        // B -> A
        k = binary_search(b, t);
        if(k == m){
            break;
        }else{
            t = b[k] + y;
            ans++;
        }
    }
    cout << ans << endl;
}