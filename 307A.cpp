#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++ ){
        ans = 0;
        for(int j = 0; j < 7; j++){
            int a; cin >> a;
            ans += a;
        }
        cout << ans << " ";
    }
    cout << endl;
}