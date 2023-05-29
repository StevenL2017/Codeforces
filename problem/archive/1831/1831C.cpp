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
    int n; cin >> n;
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }

    int ans = 1;
    function<void(int, int, int, int)> dfs = [&] (int u, int p, int f, int cnt) {
        ans = max(ans, cnt);
        for (auto [v, i] : e[u]) {
            if (v == p) continue;
            if (i < f) {
                dfs(v, u, i, cnt + 1);
            } else {
                dfs(v, u, i, cnt);
            }
        }
    };
    dfs(0, -1, n, 0);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}