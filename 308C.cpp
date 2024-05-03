#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> p;

void merge(vector<vector<double>> p, int l, int mid, int r){
    int i, j, k;
    int n1, n2;

    n1 = mid - l;
    n2 = r - mid;

    vector<vector<double>> L(n1 + 1, vector<double>(2));
    vector<vector<double>> R(n2 + 1, vector<double>(2));

    for(i = 0; i < n1; i++){
        L[i][0] = p[l + i][0];
        L[i][1] = p[l + i][1];
    }
    for(i = 0; i < n2; i++){
        R[i][0] = p[mid + i][0];
        R[i][1] = p[mid + i][1];
    }

    L[n1][1] = 1000000;
    R[n2][1] = 1000000;

    j = 0;
    k = 0;

    for(i = l; i < r; i++){
        if(L[j][1] <= R[k][1]){
            p[i][0] = L[j][0];
            p[i][1] = L[j][1];
            j++;
        }else{
            p[i][0] = R[k][0];
            p[i][1] = R[k][1];
            k++;
        }
    }
}

void merge_sort(vector<vector<double>> p, int l, int r){
    if(l + 1 < r){
        int mid;
        mid = (l + r) / 2;

        merge_sort(p, l, mid);
        merge_sort(p, mid, r);

        merge(p, l, mid, r);
    }
}

int main() {
    int n; cin >> n;
    vector<double> a(n);
    vector<double> b(n);
    p.resize(n, vector<double>(2));
    for(int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
        p.at(i).at(1) = a.at(i) / (a.at(i) + b.at(i));
        p.at(i).at(0) = i;
    }

    merge_sort(p, 0, n);

    for(int i = 0; i < n; i++) cout << p.at(i).at(0) + 1 << " ";
}