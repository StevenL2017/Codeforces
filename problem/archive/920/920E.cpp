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
    int n, m; cin >> n >> m;
    vector<set<int>> g(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    set<int> unvisited;
    rep(i, n) unvisited.insert(i);

    vi ans;
    int cnt = 0;
    function<void(int)> dfs = [&] (int node) {
        unvisited.erase(node);
        ans[cnt]++;
        int cur = -1;
        while (true) {
            auto it = unvisited.upper_bound(cur);
            if (it == unvisited.end()) break;
            cur = *it;
            if (g[node].count(cur)) continue;
            dfs(cur);
        }
    };

    rep(i, n) {
        if (unvisited.count(i)) {
            ans.push_back(0);
            dfs(i);
            cnt++;
        }
    }

    sorta(ans);
    cout << cnt << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}