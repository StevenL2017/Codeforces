#include <iostream>
#include <cstdio>
#include <climits>
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

using namespace std;

#define ll long long
#define vi vector<int>
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int N = 2e5 + 3;

vector<int> graph[N];
int status[N], pos[N], tin[N], tout[N];
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

struct Node {
    int l = 0, r = 0;
    int val = 0, lazy = 0;
};

class SegmentTree {
private:
    vector<Node> s;

public:
    SegmentTree() {}

    SegmentTree(int n) {
        s.resize(n * 4);
        build(1, 1, n);
    }

    void push(int root) {
        auto l = s[root].l, r = s[root].r;
        if (l != r && s[root].lazy) {
            auto m = l + (r - l) / 2;
            s[root * 2].val = (m - l + 1) - s[root * 2].val;
            s[root * 2].lazy ^= 1;
            s[root * 2 + 1].val = (r - m) - s[root * 2 + 1].val;
            s[root * 2 + 1].lazy ^= 1;
            s[root].lazy = 0;
        }
    }

    void merge(int root) {
        s[root].val = s[root * 2].val + s[root * 2 + 1].val;
    }

    void build(int root, int l, int r) {
        s[root].l = l, s[root].r = r;
        if (l == r) {
            s[root].val = status[pos[l]];
            return;
        }
        int m = l + (r - l) / 2;
        build(root * 2, l, m);
        build(root * 2 + 1, m + 1, r);
        merge(root);
    }
    
    void update(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            s[root].val = (r - l + 1) - s[root].val;
            s[root].lazy ^= 1;
            return;
        }
        push(root);
        int m = l + (r - l) / 2;
        if (L <= m) update(root * 2, L, R);
        if (R > m) update(root * 2 + 1, L, R);
        merge(root);
    }
    
    int query(int root, int L, int R) {
        auto l = s[root].l, r = s[root].r;
        if (L <= l && r <= R) {
            return s[root].val;
        }
        push(root);
        int ans = 0;
        int m = l + (r - l) / 2;
        if (L <= m) ans += query(root * 2, L, R);
        if (R > m) ans += query(root * 2 + 1, L, R);
        return ans;
    }
};

void solve() {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        graph[i].push_back(p);
        graph[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> status[i];
    }

    dfs(1, 0);
    SegmentTree tree(tt);

    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        int v; cin >> v;
        if (s == "pow") {
            tree.update(1, tin[v], tout[v] - 1);
        } else {
            cout << tree.query(1, tin[v], tout[v] - 1) << endl;
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