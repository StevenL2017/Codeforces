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

const int N = 1e5 + 3;

vi e[N];

int dfn[N], low[N], tt;
vector<pair<int, int>> ans;

// 因为 Tarjan 图不一定连通
// 遍历所有节点，所有未访问过的节点跑Tarjan
// tt = 0; 时间戳初始为 0
// tarjan_edge(i, -1); 从第 i 个点开始
void tarjan_edge(int u, int p) {
    low[u] = dfn[u] = ++tt;
    for (auto v: e[u]) {
        if (v == p) continue;
        if (dfn[v] == 0) {
            tarjan_edge(v, u);
            low[u] = min(low[u], low[v]); // 更新能到的最小节点编号
            ans.emplace_back(u, v);
            if (low[v] > dfn[u]) {
                cout << 0 << endl;
                exit(0);
            }
        } else {
            low[u] = min(low[u], dfn[v]); // 更新能到的最小节点编号
            if (dfn[v] < dfn[u]) {
                ans.emplace_back(u, v);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    tarjan_edge(1, 0);

    for (auto [u, v]: ans) {
        cout << u << " " << v << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}