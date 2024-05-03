#include<bits/stdc++.h>
using namespace std;
int main(){
string N;
cin >>N;
if(N.size()>3){
N.at(3)='0';
}
if(N.size()>4){
N.at(4)='0';
}
if(N.size()>5){
N.at(5)='0';
}
if(N.size()>6){
N.at(6)='0';
}
if(N.size()>7){
N.at(7)='0';
}
if(N.size()>8){
N.at(8)='0';
}
cout << N << endl;
}