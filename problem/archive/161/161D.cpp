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
    int n, k; cin >> n >> k;
    vector<vi> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    ll ans = 0;
    vector<vi> cnt(n, vi(k + 1, 0));
    function<void(int, int)> dfs = [&] (int u, int p) {
        cnt[u][0] = 1;
        for (auto v: e[u]) {
            if (v == p) continue;
            dfs(v, u);
            for (int i = 1; i <= k; i++) {
                ans += cnt[v][i - 1] * 1ll * cnt[u][k - i];
            }
            for (int i = 1; i <= k; i++) {
                cnt[u][i] += cnt[v][i - 1];
            }
        }
    };
    dfs(0, -1);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}