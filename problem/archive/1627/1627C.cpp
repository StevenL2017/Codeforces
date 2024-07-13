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

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> e(n);
    vi deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
        deg[u]++;
        deg[v]++;
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (deg[i] > 2) {
            cout << -1 << endl;
            return;
        } else if (deg[i] == 1) {
            root = i;
        }
    }

    vi a(n - 1);
    function<void(int, int, int)> dfs = [&] (int u, int p, int c) {
        for (auto [v, i]: e[u]) {
            if (v == p) continue;
            a[i] = c + 2;
            dfs(v, u, c ^ 1);
        }
    };
    dfs(root, -1, 0);

    out(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}