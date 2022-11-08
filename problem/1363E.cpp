#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vi a(n), b(n), c(n);
    int cb = 0, cc = 0;
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
        if (b[i]) cb++;
        if (c[i]) cc++;
    }
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (cb != cc) {
        cout << -1 << endl;
        return;
    }

    // min cost, cnt of 1 0, cnt of 0 1
    function<vector<ll>(int, int)> dfs = [&] (int node, int fa) -> vector<ll> {
        vector<ll> ans(3, 0);
        ans[0] = INF_LL;
        ll cost = 0;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            auto temp = dfs(nxt, node);
            cost += temp[0];
            ans[1] += temp[1];
            ans[2] += temp[2];
        }

        if (b[node] == 1 && c[node] == 0 && ans[1] < ans[2]) {
            ans[0] = min(ans[0], cost + 2 * a[node]);
        }
        else if (b[node] == 0 && c[node] == 1 && ans[1] > ans[2]) {
            ans[0] = min(ans[0], cost + 2 * a[node]);
        }
        else {
            ans[0] = min(ans[0], cost);
        }

        if (b[node] == 1 && c[node] == 0) {
            ans[1]++;
        }
        else if (b[node] == 0 && c[node] == 1) {
            ans[2]++;
        }
        ans[0] = min(ans[0], min(ans[1], ans[2]) * 2 * a[node]);
        return ans;
    };

    auto res = dfs(0, -1);
    cout << res[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}