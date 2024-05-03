#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vint = vector<int>;
using vll = vector<ll>;
using vstr = vector<str>;
using vpint = vector<pair<int, int>>;
using vbool = vector<bool>;
using vvint = vector<vint>;
using vvll = vector<vll>;

int main() {
    map<str, int> m;
    m.insert({"tourist",3858});
    m.insert({"ksun48", 3679});
    m.insert({"Benq", 3658});
    m.insert({"Um_nik", 3648});
    m.insert({"apiad", 3638});
    m.insert({"Stonefeang", 3630});
    m.insert({"ecnerwala", 3613});
    m.insert({"mnbvmar", 3555});
    m.insert({"newbiedmy", 3516});
    m.insert({"semiexp", 3481});
    str s;
    cin >> s;
    cout << m[s] << endl;
}