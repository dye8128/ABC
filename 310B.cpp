#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vint = vector<int>;

int main() {
    int n, m; cin >> n >> m;
    vint p(n);
    vector<vector<bool>> f(n,vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        int c; cin >> p.at(i) >> c;
        for(int j = 0; j < c; j++){
            int tmp; cin >> tmp;
            f.at(i).at(tmp - 1) = true;
        }
    }
    bool flag1 = false, flag2 = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(p.at(i) >= p.at(j)){
                flag1 = true;
                for(int ii = 0; ii < m; ii++){
                    if(f.at(i).at(ii)){
                        if(!f.at(j).at(ii)){
                            flag1 = false;
                            break;
                        }
                    }
                }
                if(flag1){
                    if(p.at(i) > p.at(j)){
                        flag2 = true;
                        break;
                    }
                    for(int jj = 0; jj < m; jj++){
                        if(f.at(j).at(jj)){
                            if(!f.at(i).at(jj)){
                                flag2 = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << (flag2 ? "Yes" : "No") << endl;
}