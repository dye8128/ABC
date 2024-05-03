#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a.at(i);
        sum += a.at(i);
    }
    ll ave = sum / n;
    ll sum_minus = 0, sum_plus = 0;
    for(ll i = 0; i < n; i++){
        int tmp;
        if(ave - a.at(i) >= 0){
            tmp = ave - a.at(i);
            sum_minus+=tmp;
        }else{
            tmp = a.at(i) - ave - 1;
            sum_plus+=tmp;
        }
    }
    // cout << sum_minus << " " << sum_plus << endl;
    ll ans = abs(sum_minus - sum_plus);
    ans += min(sum_minus, sum_plus);
    cout << ans << endl;
}