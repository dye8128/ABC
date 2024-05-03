#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(37,0));
    for(int i = 0; i < n; i++){
        int c; cin >> c;
        for(int j = 0; j < c; j++){
            int tmp; cin >> tmp;
            a[i][tmp] = 1;
        }
    }
    int x; cin >> x;
    int min_ = 99;
    int k = 0;
    vector<int> sum(n, 0);
    for(int i = 0; i < n; i++){
        if(a[i][x] != 1){
            a[i][x] = 100;
        }
        for(auto tmp :a[i]){
            sum[i] += tmp;
        }
        if(min_ > sum[i]){
            min_ = sum[i];
            k = 1;
        }else if(min_ == sum[i]){
            k++;
        }
    }
    cout << k << endl;
    if(min_ < 99){
        for(int i = 0; i < n; i++){
            if(sum[i] == min_){
                cout << i + 1 << " ";
            }
        }
    }
    cout << endl;
}