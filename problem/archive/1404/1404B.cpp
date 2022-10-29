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
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--; b--;
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (da * 2 >= db) {
        cout << "Alice\n";
        return;
    }

    int dab = n, d = 0, far = -1;
    function<void(int, int, int)> dfs1 = [&] (int node, int fa, int dist) {
        if (node == b) dab = min(dab, dist);
        if (dist > d) {
            d = dist;
            far = node;
        }
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            dfs1(nxt, node, dist + 1);
        }
    };
    dfs1(a, -1, 0);

    d = 0;
    function<void(int, int, int)> dfs2 = [&] (int node, int fa, int dist) {
        d = max(d, dist);
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            dfs2(nxt, node, dist + 1);
        }
    };
    dfs2(far, -1, 0);

    if (dab <= da || da * 2 >= d) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}