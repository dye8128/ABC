#include <iostream>
using namespace std;

int main() {
    long a, b;
    cin >> a >> b;
    long t = 0;
    t = a / b;
    if(a % b != 0) t++;
    cout << t << endl;
}