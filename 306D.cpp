#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    int n; cin >> n;
    ll ans = 0;
    vector<pair<int, ll>> xy(n,{0, 0});
    for(int i = 0; i < n; i++){
        cin >> xy.at(i).first >> xy.at(i).second;
    }
    ll tmp = 0;
    int i = 0;
    while(i < n){
        while(i < n && xy.at(i).first == 1){
            tmp = max(tmp, xy.at(i).second);
            i++;
        }
        ll tmp2 = -1 * pow(10, 10);
        bool flag = false;
        for(; i < n; i++){
            //cout << tmp2 << endl;
            if(xy.at(i).first == 0){
                if(xy.at(i).second > 0){
                    ans += xy.at(i).second + tmp;
                    tmp = 0;
                    flag = true;
                }else{
                    tmp2 = max(tmp2, xy.at(i).second);
                }
            }else{
                if(!flag){
                    ans += max(tmp + tmp2, ll(0));
                    tmp = 0;
                }
                break;
            }
        }
    }
    ans += max(ll(0), tmp);
    cout << ans << endl;
}