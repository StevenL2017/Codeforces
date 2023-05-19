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

const int N = 503;

int n, m, k;
vector<int> e[N];

int vis[N];

void dfs(int u) {
    vis[u] = 1;
    for (auto v : e[u]) {
        if (vis[v] == 1) k++;
        else if (vis[v] == 0) dfs(v);
    }
    vis[u] = 2;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        k = 0;
        dfs(i);
        for (int j = 1; j <= n && k <= 1; j++) {
            if (vis[j]) continue;
            dfs(j);
        }
        if (k <= 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}