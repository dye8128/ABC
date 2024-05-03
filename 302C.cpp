#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> nums;
    for(int i = 0; i < n; i++){
        cin >> s.at(i);
        nums.push_back(i);
    }
    
    int flag1, flag;
    do{
        flag1 = 0;
        for(int i = 0; i < n - 1; i++ ) {
            flag = 0;
            for(int j = 0; j < m; j++ ) {
                flag += (s.at(nums.at(i)).at(j) != s.at(nums.at(i + 1)).at(j));
            }
            if(flag == 1) flag1++;
        }
        if(flag1 == n - 1){
            cout << "Yes" << endl;
            return 0;
        }
    }while (next_permutation(nums.begin(), nums.end()));
    cout << "No" <<  endl;
}