#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vint = vector<int>;
using vll = vector<ll>;
using vstr = vector<str>;
using vpint = vector<pair<int, int>>;
using vbool = vector<bool>;
using vvint = vector<vint>;
using vvll = vector<vll>;

int main() {
    ll n, d; cin >> n >> d;
    ll p; cin >> p;
    vll f(n);
    vll price_to_i(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> f.at(i);
    }
    sort(f.begin(), f.end());
    for(int i = 0; i < n; i++){
        sum += f.at(i);
        price_to_i[i] = sum;
    }
    // for(auto v: f){
    //     cout << v << " ";
    // }cout << endl;
    vll price_pass(n);
    for(int i = 0; i < n; i++){
        price_pass[i] = price_to_i[i] + ((n - i - 2 + d) / d) * p;
    }
    price_pass.emplace_back((n + d - 1)/d*p);
    // for(auto v: price_pass){
    //     cout << v << " ";
    // }
    sort(price_pass.begin(), price_pass.end());
    cout << price_pass[0] << endl;
}