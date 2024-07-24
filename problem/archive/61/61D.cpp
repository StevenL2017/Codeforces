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
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u - 1].emplace_back(v - 1, w);
        e[v - 1].emplace_back(u - 1, w);
        ans += 2ll * w;
    }
    ll mx = 0;
    function<void(int, int, ll)> dfs = [&] (int u, int p, ll s) {
        mx = max(mx, s);
        for (auto [v, w]: e[u]) {
            if (v == p) continue;
            dfs(v, u, s + w);
        }
    };
    dfs(0, -1, 0);
    cout << ans - mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}