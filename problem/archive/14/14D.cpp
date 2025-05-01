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
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vi dia(n);
    function<int(int, int)> dfs = [&] (int u, int p) -> int {
        dia[u] = 0;
        int cur = 0;
        for (auto v: e[u]) {
            if (v == p) {
                continue;
            }
            int nxt = dfs(v, u) + 1;
            dia[u] = max({dia[u], dia[v], cur + nxt});
            cur = max(cur, nxt);
        }
        return cur;
    };

    int ans = 0;
    for (int u = 0; u < n; u++) {
        for (auto v: e[u]) {
            if (u >= v) {
                continue;
            }
            dfs(u, v);
            dfs(v, u);
            ans = max(ans, dia[u] * dia[v]);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}