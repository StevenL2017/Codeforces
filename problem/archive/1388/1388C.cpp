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
    vi p(n), h(n); in(p), in(h);
    vector<vi> graph(n);
    rep(i, n - 1) {
        int x, y; cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vi people(n, 0);
    function<int(int, int)> dfs1 = [&] (int node, int fa) -> int {
        int ans = p[node];
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            ans += dfs1(nxt, node);
        }
        people[node] = ans;
        return ans;
    };
    dfs1(0, -1);

    function<int(int, int)> dfs2 = [&] (int node, int fa) -> int {
        auto s = people[node];
        auto d = h[node];
        if (s + d < 0 || s - d < 0 || (s - d) % 2 != 0) return INF;

        int bad = 0;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            auto temp = dfs2(nxt, node);
            if (temp == INF) return INF;
            bad += temp;
        }
        if ((s - d) / 2 > bad + p[node]) return INF;
        return (s - d) / 2;
    };
    int bad = dfs2(0, -1);

    if (bad < INF) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}