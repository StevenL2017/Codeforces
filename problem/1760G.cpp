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
    int n, a, b;
    cin >> n >> a >> b;
    a--; b--;
    vector<vector<pair<int, int>>> graph(n);
    rep(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    set<int> cand;
    function<void(int, int, int)> dfs1 = [&] (int node, int fa, int x) {
        if (node != a && node != b) cand.insert(x);
        for (auto& [nxt, w]: graph[node]) {
            if (nxt == fa) continue;
            dfs1(nxt, node, x ^ w);
        }
    };
    dfs1(b, -1, 0);

    function<bool(int, int, int)> dfs2 = [&] (int node, int fa, int x) -> bool {
        if (node == b) {
            if (x == 0) return true;
            else return false;
        } else {
            if (cand.count(x)) return true;
        }
        for (auto& [nxt, w]: graph[node]) {
            if (nxt == fa) continue;
            if (dfs2(nxt, node, x ^ w)) return true;
        }
        return false;
    };
    bool ok = dfs2(a, -1, 0);

    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}