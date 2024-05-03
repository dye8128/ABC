#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(3*n);
    vector<vector<int>> f(3, vector<int>(n + 1));
    vector<int> sorted(n + 1);
    for(int i = 0; i < 3 * n; i ++){
        cin >> a.at(i);
        int tmp = a.at(i);
        f.at(1).at(tmp) ++;
        if(f.at(1).at(tmp) == 2){
            f.at(0).at(tmp) = i;
            sorted.at(tmp) = i;
        }
        f.at(2).at(tmp) = tmp;
    }
    sort(sorted.begin(), sorted.end());
    map<int, int> map{};
    /*for(int i = 1; i < n + 1; i++){
        cout << " f("<< f.at(2).at(i) << "): " << f.at(0).at(i);
    }
    cout << endl;
    for(int i = 0; i < n + 1; i++){
        cout << sorted.at(i) << " ";
    }
    cout << endl;*/
    for(int i = 0; i < n + 1; i++){
        map.insert({f.at(0).at(i), f.at(2).at(i)});
    }
    for(int i = 1; i < n + 1; i++){
       auto item = map.find(sorted.at(i));
       cout << item->second << " ";
       //map.erase(item);
    }
    
}