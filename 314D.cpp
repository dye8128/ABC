#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    struct txc{
        int t;
        int x;
        char c;
    };
    vector<txc> vec(q);
    int t = 0;
    int num = 0;
    for(int i = 0; i < q; i++){
        cin >> vec[i].t >> vec[i].x >> vec[i].c;
        vec[i].x--;
        if(vec[i].t == 1){
            int x = vec[i].x;
            s[x] = vec[i].c;
        }else{
            //最後のt=2,3
            t = vec[i].t;
            num = i;
        }
    }
    if(t == 2){
        for(int i = 0; i < n; i++){
            if(s[i] < 'a') s[i] += 32;
        }
    }
    if(t == 3){
        for(int i = 0; i < n; i++){
            if(s[i] > 'Z') s[i] -= 32;
        }
    }
    for(int i = num + 1; i < q; i++){
        int x = vec[i].x;
        s[x] = vec[i].c;
    }
    cout << s << endl;
}