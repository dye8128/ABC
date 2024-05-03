#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void lists(vector<ll> a){
    for(int i = 0; i < a.size(); i++ ) {
        cout << a.at(i) << " ";
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> b, c(n/2);
    for(int i = 0; i < n; i++) {
        cin >> a.at(i);
        if(i != 0 && i%2 == 0) {
            c.at(i/2 - 1) = a.at(i) - a.at(i - 1);
        }
    }
    //lists(a);lists(c);
    
    int q; cin >> q;
    for(int I = 0; I < q; I++ ) {
        ll l, r; cin >> l >> r;
        int ans = 0;
        int i = 1;
        //i回目 2i-1 ~ 2i
        while(l >= a.at(2*i - 1)) i++;
        i--;
        if(l < a.at(2*i)) {
            ans+= a.at(2*i) - l;
            //cout << ans <<endl;
        }
        i++;
        while(a.at(2*i) < r){
            ans+= c.at(i - 1);
            i++;
            //cout << ans <<endl;
        }
        if(a.at(2*i - 1) < r) ans+= r - a.at(2*i - 1);
        cout << ans << "\n";
        if(ans < 0) ans = 0;
        b.push_back(ans);
    }
    /*for(int i = 0; i < b.size(); i++ ) {
        cout << b.at(i) << "\n";
    }*/
}