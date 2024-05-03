#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vpll = vector<pair<ll, ll>>;

ll Meguru_Binary_Search(vll a, ll p){
    ll ok = 0, ng = a.size(), m;
    while(abs(ok-ng)>1){
        m = (ok+ng)/2;
        if(a[m] < p){
            ok = m;
        }else{
            ng = m;
        }
    }
    return ok;
}

int main() {
    ll w,h,n; cin >> w >> h >> n;
    vpll cake(n);
    for(ll i = 0; i < n; i++){
        cin >> cake[i].first >> cake[i].second;
    }
    ll a_n, b_n;
    cin >> a_n;
    ll a[a_n+1];a[a_n] = h;
    for(ll i = 0; i < a_n; i++){
        cin >> a[i];
    }
    cin >> b_n;
    ll b[b_n + 1];b[b_n] = w;
    for(ll i = 0; i < b_n; i++){
        cin >> b[i];
    }
    vvll area(a_n+1,vll(b_n+1, 0));
    vll num(n+1,0); num[0] = (a_n+1) * (b_n+1);
    for(ll i = 0; i < n; i++){
        // ll x = Meguru_Binary_Search(a, cake[i].first);
        // ll y = Meguru_Binary_Search(b, cake[i].second);
        ll x = *lower_bound(a+1,a+a_n+2,cake[i].first);
        ll y = *lower_bound(b+1,b+b_n+2,cake[i].second);
        // cout << x << " " << y << endl;
        area[x][y]++;
        num[area[x][y]-1]--;num[area[x][y]]++;
    }
    // for(auto v : num)cout << v;cout << endl;
    ll m = 1e9, M;
    for(ll i = 0; i < n + 1; i++){
        if(num[i] > 0){
            M = i;
            if(num[i] < m){
                m = i;
            }
        }
        if(num[0] > 0)m = 0;
    }
    cout << m <<" "<< M << endl;
}