#include <bits/stdc++.h>
using namespace std;

struct value{
    int x;
    int y;
};

int distance(int x1, int x2, int y1, int y2) {
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

vector<vector<int>> check(vector<vector<int>> a, int &NewInfected, vector<value> values, int *infected, int d) {
    vector<vector<int>> b(0, vector<int>(2, 0));
    for(int i = 0; i < a.size(); i++ ) {
        for(int j = 0; j < values.size(); j++ ) {
            if(infected[j] == 0) {
                if(distance(values.at(j).x, a.at(i).at(0), values.at(j).y, a.at(i).at(1)) <= d){
                    infected[j] = 1;
                    NewInfected++;
                    b.push_back({values.at(j).x, values.at(j).y});
                }
            }
        }
    }
    return b;
}

int main() {
    int n, d; cin >> n >> d;
    d*=d;
    vector<value> values(n, {0, 0});
    vector<int> infected(n, 0);
    infected.at(0) = 1;
    for(int i = 0; i < n; i++ ) {
        cin >> values.at(i).x >> values.at(i).y;
    }
    int NewInfected = 1;
    vector<vector<int>> a(0 , vector<int>(2, 0));
    a.push_back({values.at(0).x, values.at(0).y});
    do{
        NewInfected = 0;
        a = check(a, NewInfected, values, &infected.at(0), d);
    }while(NewInfected != 0);
    for(int i = 0; i < n; i++ ) {
        if(infected.at(i) == 0) cout << "No\n";
        else cout << "Yes\n";
    }
}