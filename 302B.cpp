#include <iostream>
#include <string>
#include <vector>
using namespace std;

int check(int dir, char target, vector<string> s, int &i, int &j) {
    int flag = 0;
    int h, w;
    h = s.size();
    w = s.at(0).size();
    switch (dir)
    {
    case 1:
        if(i < h - 1){
            if(s.at(i + 1).at(j) == target) flag = 1;
        }
        i++;
        break;
    case 2:
        if(j > 0 && i < h - 1){
            if(s.at(i + 1).at(j - 1) == target) flag = 1;
        }
        i++;
        j--;
        break;
    case 3:
        if(j > 0){
            if(s.at(i).at(j - 1) == target) flag = 1;
        }
        j--;
        break;
    case 4:
        if(j > 0 && i > 0){
            if(s.at(i - 1).at(j - 1) == target) flag = 1;
        }
        i--;
        j--;
        break; 
    case 5:
        if(i > 0){
            if(s.at(i - 1).at(j) == target) flag = 1;
        }
        i--;
        break;
    case 6:
        if(j < w - 1){
            if(s.at(i).at(j + 1) == target) flag = 1;
        }
        j++;
        break;
    case 7:
        if(j < w - 1 && i < h - 1){
            if(s.at(i + 1).at(j + 1) == target) flag = 1;
        }
        i++;
        j++;
        break;
    case 8:
        if(j < w - 1 && i > 0){
            if(s.at(i - 1).at(j + 1) == target) flag = 1;
        }
        i--;
        j++;
        break;                   
    default:
        break;
    }
    return flag;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> res(5, vector<int>(2));
    string tar = "snuke";
    for(int i = 0; i < h; i++) cin >> s.at(i);

    for(int i = 0; i < h; i++ ) {
        for(int j = 0; j < w; j++) {
            if(s.at(i).at(j) == 's') {
                for(int k = 1; k < 9; k++) {
                    int ii = i;
                    int jj = j;
                    res.at(0).at(0) = i;
                    res.at(0).at(1) = j;
                    if(check(k, 'n', s, ii, jj) == 1) {
                        res.at(1).at(0) = ii;
                        res.at(1).at(1) = jj;
                        int flag = 0;
                        for(int l = 2; l < 5; l++) {
                            flag+=check(k, tar.at(l), s, ii, jj);
                            res.at(l).at(0) = ii;
                            res.at(l).at(1) = jj;
                        }
                        if(flag == 3) {
                            for(int m = 0; m < 5; m++) {
                                cout << res.at(m).at(0)  + 1 <<" "<< res.at(m).at(1) + 1 << endl;
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }

}