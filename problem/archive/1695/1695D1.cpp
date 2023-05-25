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
    vector<vi> e(n);
    vi deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    int mx = *max_element(deg.begin(), deg.end());
    if (mx == 0) {
        cout << 0 << endl;
        return;
    } else if (mx < 3) {
        cout << 1 << endl;
        return;
    }

    function<int(int, int)> dfs = [&] (int u, int p) -> int {
        int sz = 0, no = 0;
        for (auto v : e[u]) {
            if (v == p) continue;
            auto nxt = dfs(v, u);
            sz += nxt;
            if (nxt == 0) no++;
        }
        return sz + max(0, no - 1);
    };
    for (int i = 0; i < n; i++) {
        if (deg[i] >= 3) {
            cout << dfs(i, -1) << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}