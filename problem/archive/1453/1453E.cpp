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
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int ans = 0;
    function<int(int, int)> dfs = [&] (int u, int p) -> int {
        if (ssz(e[u]) == 1 && p != -1) {
            return 1;
        }
        vi a;
        for (auto v: e[u]) {
            if (v == p) continue;
            auto r = dfs(v, u);
            a.push_back(r);
        }
        sort(a.begin(), a.end());
        ans = max(ans, a[0]);
        if (ssz(a) > 1) {
            if (u == 0) {
                ans = max({ans, a.back(), a[ssz(a) - 2] + 1});
            } else {
                ans = max(ans, a.back() + 1);
            }
        }
        return a[0] + 1;
    };
    dfs(0, -1);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}