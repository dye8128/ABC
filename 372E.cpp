#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using vc = vector<T>;
template<class T>using vvc = vc<vc<T>>;
using vint = vc<int>;
using vll = vc<ll>;
using vstr = vc<str>;
using vpint = vc<pint>;
using vpll = vc<pll>;
using vbool = vc<bool>;
using vvint = vvc<int>;
using vvll = vvc<ll>;
using vvvll = vvc<vll>;
using vvpll = vvc<pll>;
using pqueue = priority_queue<ll, vll, greater<ll>>;

#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n)          for(ll i = 0; i < (n); ++i)
#define rep2(i, n)       for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b)    for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define each1(a)       for(auto&& i : a)
#define each2(i,a)     for(auto&& i : a)
#define each3(x,y,a)   for(auto&& [x, y] : a)
#define each4(x,y,z,a) for(auto&& [x, y, z] : a)
#define each(...) overload4(__VA_ARGS__, each4, each3, each2, each1)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()

void yesno(bool flag){cout << (flag ? "Yes" : "No") << endl;}

// Union-Find
struct UnionFind {
    vector<int> par, rank, siz;

    // 新たな配列
    vector<int> min_node;

    // 構造体の初期化
    UnionFind(int n) : par(n,-1), rank(n,0), siz(n,1), min_node(n) {
        // 初期状態では min_node は自分自身
        for (int v = 0; v < n; ++v) min_node[v] = v;
    }

    // 根を求める
    int root(int x) {
        if (par[x]==-1) return x; // x が根の場合は x を返す
        else return par[x] = root(par[x]); // 経路圧縮
    }

    // x と y が同じグループに属するか (= 根が一致するか)
    bool issame(int x, int y) {
        return root(x)==root(y);
    }

    // x を含むグループと y を含むグループを併合する
    bool merge(int x, int y) {
        int rx = root(x), ry = root(y); // x 側と y 側の根を取得する
        if (rx==ry) return false; // すでに同じグループのときは何もしない
        // union by rank
        if (rank[rx]<rank[ry]) swap(rx, ry); // ry 側の rank が小さくなるようにする
        par[ry] = rx; // ry を rx の子とする
        if (rank[rx]==rank[ry]) rank[rx]++; // rx 側の rank を調整する
        siz[rx] += siz[ry]; // rx 側の siz を調整する

        // min_node の更新
        min_node[rx] = min(min_node[rx], min_node[ry]);
        
        return true;
    }

    // x を含む根付き木のサイズを求める
    int size(int x) {
        return siz[root(x)];
    }

    // 追加: x を含む根付き木の中での頂点番号の最小値
    int get_min_node(int x) {
        return min_node[root(x)];
    }
};

int main() {
    ll n; cin >> n; ll q; cin >> q;
    UnionFind uf(n);
    vc<set<ll>> st(n);
    rep(n) st[i].insert(-i-1);

    rep(_,q){
        ll t; cin >> t;
        if(t == 1){
            ll u, v; cin >> u >> v;
            --u; --v;
            ll um = uf.get_min_node(u), vm = uf.get_min_node(v);
            if(um < vm) st[um].merge(st[vm]);
            else if(vm < um) st[vm].merge(st[um]);
            uf.merge(u, v);
            ll min_node = uf.get_min_node(u);
            st[min_node].insert(-u-1);
            st[min_node].insert(-v-1);
            if(st[min_node].size() > 10){
                st[min_node].erase((next(st[min_node].begin(),10)), st[min_node].end());
            }
        }else{
            ll v, k; cin >> v >> k;
            --v;
            ll min_node = uf.get_min_node(v);
            // cout << min_node << ":" << endl;
            if(st[min_node].size() < k){
                cout << -1 << endl;
            }else{
                // each(st[min_node]){
                //     cout << i << " ";
                // } cout << endl;
                cout << -*(next(st[min_node].begin(),k-1)) << endl;
            }
        }
    }
}