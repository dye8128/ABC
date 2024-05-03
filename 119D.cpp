#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll binary_search(vll& a, ll x){
    ll ok = a.size(), ng = -1, m;
    while(abs(ok-ng)>1){
        m = (ok+ng)/2;
        if(a[m] >= x){
            ok = m;
        }else{
            ng = m;
        }
    }
    return ok;
}

bool in(ll i, ll n){
    return i >= 0 && i < n;
}

int main() {
    ll a, b, q; cin >> a >> b >> q;
    vll s(a), t(b), x(q);
    for(ll i = 0; i < a; i++){
        cin >> s[i];
    }
    for(ll i = 0; i < b; i++){
        cin >> t[i];
    }
    for(ll i = 0; i < q; i++){
        cin >> x[i];
    }
    ll m = 1e11, j, k, l;
    for(ll i = 0; i < q; i++){
        ll m = 1e11;
        j = binary_search(s, x[i]);
        k = binary_search(t, x[i]);
        // 東東
        if(in(j,a) && in(k,b)){
            l = max(s[j], t[k]) - x[i];
            m = min(l, m);
        }
        // 西西
        if(in(j-1,a) && in(k-1,b)){
            l = x[i] - min(s[j-1], t[k-1]);
            m = min(l, m);
        }
        // 西東
        if(in(j-1,a) && in(k,b)){
            l = t[k] - s[j-1] + min(t[k] - x[i], x[i] - s[j-1]);
            m = min(l, m);
        }
        // 東西
        if(in(j,a) && in(k-1,b)){
            l = s[j] - t[k-1] + min(s[j] - x[i], x[i] - t[k-1]);
            m = min(l, m);
        }
        cout << m << endl;
    }
}