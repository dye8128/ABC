#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) cin >> s.at(i);
    int i = 0;
    while(s.at(i/w).at(i%w)=='.'){
        i++;
    }
    int i0 = i/w, j0 = i%w;
    //cout << i0 <<" "<< j0 << endl;
    i=0;
    while(j0 + i < w && s.at(i0).at(j0+i)=='#'){
        i++;
    }
    int j1 = j0 + i - 1;
    //cout << j1 << endl;
    //1列目に抜け
    if(j1 < w - 1 && s.at(i0).at(j1 + 1) == '.' && s.at(i0 + 1).at(j1 + 1) == '#') {
        cout << i0 + 1 << " " << j1 + 2 << endl;
        return 0;
    }
    //1列目以外or左上
    i=0;
    int flag;
    int j = 0;
    //cout << j1 - j0 << endl;
    do{
        j = 0;
        flag = 0;
        while(i0 + i < h && j <= j1 - j0) {
            if(s.at(i0 + i).at(j0 + j)=='#') flag++;
            j++;
            //cout << i0 + i << " " << flag << endl;
        }
        i++;
        //cout << flag << endl;
    }while(flag == j1 - j0 + 1);
    //左上
    if(flag == 0) {
        cout << i0 + 1 << " " << j0 << endl;
        return 0;
    }
    //1列目以外
    int i1 = i0 + i - 1;
    j = 0;
    while(s.at(i1).at(j0 + j) == '#') {
        j++;
    }
    cout << i1 + 1 << " " << j0 + j + 1 << endl;

}