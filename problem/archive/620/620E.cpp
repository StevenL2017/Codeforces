#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>

using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

const int MAXN = 5e5 + 3;

vector<int> graph[MAXN];
int status[MAXN], pos[MAXN], tin[MAXN], tout[MAXN];
int tt = 1;

// tin[node] 和 tout[node] 为左闭右开区间
// tt 初始化为 1 使得线段树根节点为 1
void dfs(int node, int fa) {
    pos[tt] = node;
    tin[node] = tt++;
    for (auto& nxt: graph[node]) {
        if (nxt == fa) continue;
        dfs(nxt, node);
    }
    tout[node] = tt;
}

class SegmentTree {
private:
    vector<long long> mask; // 存储节点所代表的子树的状态，从下到上merge状态
    vector<long long> add; // 存储节点所代表的子树的更新值，从上到下push更新值

public:
    SegmentTree(int n) {
        mask.resize(n * 4);
        add.resize(n * 4);
    }

    void build(int root, int l, int r) {
        add[root] = -1;
        if (l + 1 == r) {
            mask[root] = 1ll << status[pos[l]];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m, r);
        mask[root] = mask[root * 2] | mask[root * 2 + 1];
    }

    void push(int root) {
        if (add[root] == -1) return;
        for (int i = 0; i < 2; i++) {
            mask[root * 2 + i] = add[root * 2 + i] = add[root];
        }
        add[root] = -1;
    }
    
    void update(int root, int l, int r, int L, int R, int val) {
        if (L >= R) return;
        if (L == l && r == R) {
            mask[root] = 1ll << val;
            add[root] = 1ll << val;
            return;
        }
        push(root);
        int m = l + (r - l) / 2;
        update(root * 2, l, m, L, min(m, R), val);
        update(root * 2 + 1, m, r, max(m, L), R, val);
        mask[root] = mask[root * 2] | mask[root * 2 + 1];
    }
    
    long long query(int root, int l, int r, int L, int R) {
        if (L >= R) return 0;
        if (L == l && r == R) {
            return mask[root];
        }
        push(root);
        long long ans = 0;
        int m = l + (r - l) / 2;
        ans |= query(root * 2, l, m, L, min(m, R));
        ans |= query(root * 2 + 1, m, r, max(m, L), R);
        return ans;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    rep(i, n) cin >> status[i + 1];
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    SegmentTree tree(n);
    tree.build(1, 1, n + 1);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int v, c; cin >> v >> c;
            tree.update(1, 1, n + 1, tin[v], tout[v], c);
        } else {
            int v; cin >> v;
            ll mask = tree.query(1, 1, n + 1, tin[v], tout[v]);
            cout << __builtin_popcountll(mask) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}