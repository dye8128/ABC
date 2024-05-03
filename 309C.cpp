#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    ll n, k; cin >> n >> k;
    vector<vector<ll>> med(n, vector<ll>(2));
    for(ll i = 0; i < n; i++){
        cin >> med.at(i).at(0) >> med.at(i).at(1);
    }
    vector<ll> p(n);
    iota(p.begin(), p.end(), 0);
    auto f = [&](ll i, ll j) {
        return med.at(i).at(0) < med.at(j).at(0);
    };
    sort(p.begin(), p.end(), f);
    //for(ll i = 0; i < n; i++) cout << p.at(i) << " ";

    ll num = 0;
    for(ll i = 0; i < n; i++){
        num += med.at(i).at(1);
    }
    ll day = 0;
    for(ll i = 0; i < n; i++){
        if(num <= k){
            cout << day + 1 << endl;
            return 0;
        }
        day = med.at(p.at(i)).at(0);
        num -= med.at(p.at(i)).at(1);
    }
    cout << day + 1 << endl;
}