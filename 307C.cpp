#include <bits/stdc++.h>
using namespace std;

int main() {
    int ha, wa, hb , wb, hx, wx;
    int black = 0;
    cin >> ha >> wa;
    vector<string> a(ha);
    for(int i = 0; i < ha; i++ ) cin >> a.at(i);
    cin >> hb >> wb;
    vector<string> b(hb);
    for(int i = 0; i < hb; i++ ) cin >> b.at(i);
    cin >> hx >> wx;
    vector<string> x(hx);
    for(int i = 0; i < hx; i++ ){
        cin >> x.at(i);
        for(int j = 0; j < wx; j++){
            if(x.at(i).at(j) == '#') black++;
        }
    }

    bool flag = true;
    string d = {};
    int hc, wc;
    hc = ha + 2 * hb + 2 * hx;
    wc = wa + 2 * wb + 2 * wx;
    for(int k = 0; k < wc + 40; k++){
        d.push_back('.');
    }
    for(int i = 0; i < hc - hb + 1; i++){
        for(int j = 0; j < wc - wb + 1; j++){
            vector<string> c(hc + 40, d);
            int check = 0;
            for(int k = 0; k < hc; k++){
                char tmpA = '.';
                char tmpB = '.';
                for(int l = 0; l < wc; l++){
                    tmpA = '.', tmpB = '.';
                    if(k >= i && k - i < hb && l >= j && l - j < wb){
                        tmpB = b.at(k - i).at(l - j);
                    }
                    if(k >= hb + hx && k < ha + hb + hx && l >= wb + wx && l < wa + wb + wx){
                        tmpA = a.at(k - hb - hx).at(l - wb - wx);
                    }
                    if(tmpA == '#' || tmpB == '#'){
                        c.at(k + 20).at(l + 20) = '#';
                        check++;
                    }
                }
            }
            /*if(i == 0 && j == 0){
                for(int k = 10; k < hc + 10; k++){
                    cout << c.at(k) << endl;
                }
            }*/
            if(check == black){
                for(int k = 0; k <= hc - hx + 40; k++){
                    for(int l = 0; l <= wc - wx + 40; l++){
                        flag = true;
                        for(int m = 0; m < hx; m++){
                            for(int n = 0; n < wx; n++){
                                if(c.at(k + m).at(l + n) != x.at(m).at(n)){
                                    flag = false;
                                    break;
                                }
                            }
                            if(!flag) break;
                        }
                        if(flag){
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}