#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()

ll binary_search(vll& a, ll b, function<bool(ll, ll)> is_ok, ll ok, ll ng){
    ll m;
    while(abs(ok - ng) > 1){
        m = (ok + ng)/2l;
        is_ok(a[m], b) ? ok = m :ng = m;
    }
    return ok;
}

int main() {
    ll n;cin >> n;
    vll a(n), b(n), c(n);
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(all(a));sort(all(c));
    auto leq = [](ll a, ll b) -> bool{return (a <= b);};
    auto geq = [](ll a, ll b) -> bool{return (a >= b);};

    for(ll i = 0; i < n; i++){
        ll x = binary_search(a, b[i], geq, n, -1);
        ll y = n - 1 - binary_search(c, b[i], leq, -1, n);
        ans += x * y;
    }
    cout << ans << endl;
}
