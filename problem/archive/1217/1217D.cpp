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
    vector<vector<pair<int, int>>> graph(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].emplace_back(v, i);
    }

    vi pos(n, 0), color(m, 0);
    bool has_loop = false;
    function<void(int)> dfs = [&] (int node) {
        pos[node] = 1;
        for (auto& [nxt, i]: graph[node]) {
            if (pos[nxt] == 0) {
                dfs(nxt);
                color[i] = 1;
            }
            else if (pos[nxt] == 1) {
                color[i] = 2;
                has_loop = true;
            }
            else {
                color[i] = 1;
            }
        }
        pos[node] = 2;
    };

    rep(i, n) {
        if (pos[i] == 0) dfs(i);
    }

    cout << (has_loop ? 2 : 1) << endl;
    out(color);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}