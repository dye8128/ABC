#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> a(w);
    for(int i = 0; i < h; i++ ) {
        string s;
        for(int j = 0; j < w; j++ ) {
            cin >> a.at(j);
            if(j == 0) s.push_back('.');
            else s.push_back('A' - 1 + j);
        }
        cout << s << endl;

    }
}