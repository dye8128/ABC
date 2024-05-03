#include <bits/stdc++.h>
using namespace std;
/*A,B,C... に操作を対応させる -> p - 'A' で int に変換*/
int change(char c){
    switch (c)
    {
    case 'A':
        return 0;
    case 'B':
        return 3;
    case 'C':
        return 4;
    case 'D':
        return 8;
    case 'E':
        return 9;
    case 'F':
        return 14;
    case 'G':
        return 23;
    }
    return 0;
}

int main() {
    char p, q; cin >> p >> q;

    cout << abs(change(p)-change(q)) << endl;

}