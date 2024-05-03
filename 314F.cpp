#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll M = 998244353;

ll pow(ll a, ll n){
    if(n == 0){
        return 1;
    }else if(n % 2 == 1){
        return a * pow(a, n -1) % M;
    }else{
        ll tmp = pow(a, n / 2);
        return tmp * tmp % M;
    }
}

ll inv(ll a) {
    return pow(a, M - 2);
}

int main() {
    ll n; cin >> n;
    vector<pair<ll, ll>> pq(n - 1,pair<ll, ll>());
    for(ll i = 0; i < n - 1; i++){
        cin >> pq[i].first >> pq[i].second;
        pq[i].first--; pq[i].second--;
    }
    vector<ll> e(n,0);
    set<set<ll>> teams;
    for(ll i = 0; i < n; i++){
        teams.insert({i});
    }
    for(ll i = 0; i < n - 1; i++){
        ll p = pq[i].first, q = pq[i].second;
        set<ll> t_a, t_b, t_new;
        for(auto team : teams){
            auto itr = team.find(p);
            if(itr != team.end()){
                t_a = team;
                break;
            }
        }
        for(auto team : teams){
            auto itr = team.find(q);
            if(itr != team.end()){
                t_b = team;
                break;
            }
        }
        ll a = t_a.size();
        ll b = t_b.size();
        for(auto member: t_a){
            ll tmp = a * inv(a + b);
            e[member] += tmp;
        }
        for(auto member: t_b){
            ll tmp = b * inv(a + b);
            e[member] += tmp;
        }
        set_union(t_a.begin(), t_a.end(), t_b.begin(), t_b.end(), inserter(t_new, t_new.begin()));
        teams.erase(t_a);
        teams.erase(t_b);
        teams.insert(t_new);
        // cout << "teams: " <<endl;
        // for(auto team: teams){
        //     for(auto m: team) cout << m <<" ";
        //     cout << endl;
        // }
    }
    for(ll i = 0; i < n; i++){
        cout << e[i] % M << " ";
    }
}