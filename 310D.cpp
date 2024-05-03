#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vint = vector<int>;

int main() {
    int n, t, m; cin >> n >> t >> m;
    vector<vint> bad(n, vint(n));
    vint loop(n); //iを含むループの最大次数 - 1 = iが所属できないチーム数
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;b--;
        //相性悪いと1
        bad[a][b] = 1;
        bad[b][a] = 1;
    }
    for(int i = 0; i < n; i++){
        vint tmp;
        vector<bool> seen(n);
        for(int j = 0; j < n; j++){
            if(bad[i][j]){
                tmp.emplace_back(j);
                seen[j] = true;
            }
        }
        int j = 0;
        // while(tmp.size() != 0){
        //     vint add;
        //     j++;
        //     for(auto person : tmp){
        //         for(int k = 0; k < n; k++){
        //             if(bad[person][k]&&!seen[k]){
        //                 add.emplace_back(k);
        //                 if()
        //             }
        //         }
        //     }
        // }
    }
    ll ans = 1;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        for(int j = 0; j < i; j++){
            tmp++;
        }
        ans *= ll(t - tmp);
    }
}