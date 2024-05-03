#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll M = 998244353;

ll pow(ll a, ll n){
    if(n == 0){
        return 1;
    }else if(n % 2 == 1){
        return a * pow(a, n -1) % M;
    }else{
        ll tmp = pow(a, n / 2);
        return tmp * tmp % M;
    }
}

ll inv(ll a) {
    return pow(a, M - 2);
}

int main() {
    ll m,n; cin >> n >> m;
    ll ans;
    ans = pow(m - 1, n);
    if(n % 2 == 0) ans += m - 1;
    else ans -= m - 1;
    ans %= M;
    if(ans < 0) ans += M;
    cout << ans << endl;
}