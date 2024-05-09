#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;

ll a, b, x;

ll binary_search(){
    ll ok = 0, ng = 1e9+1, m;
    while(abs(ok - ng) > 1){
        m = (ok+ng)/2;
        str m_s = to_string(m);
        ll d = m_s.size();
        a * m + b * d <= x ? ok = m : ng = m;
    }
    return ok;
}

int main() {
    cin >> a >> b >> x;
    cout << binary_search() << endl;
}