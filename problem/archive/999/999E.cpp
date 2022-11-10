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
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vi> graph(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }

    vi connected(n, 0);
    function<void(int)> dfs1 = [&] (int node) {
        connected[node] = 1;
        for (auto& nxt: graph[node]) {
            if (connected[nxt]) continue;
            dfs1(nxt);
        }
    };
    dfs1(s);
    
    vector<pair<int, int>> cand;
    rep(i, n) {
        if (!connected[i]) {
            int cnt = 0;
            vi visited(n, 0);
            function<void(int)> dfs2 = [&] (int node) {
                visited[node] = 1;
                cnt++;
                for (auto& nxt: graph[node]) {
                    if (connected[nxt] || visited[nxt]) continue;
                    dfs2(nxt);
                }
            };
            dfs2(i);
            cand.emplace_back(cnt, i);
        }
    }
    sortd(cand);

    int ans = 0;
    for (auto& [_, node]: cand) {
        if (!connected[node]) {
            ans++;
            dfs1(node);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}