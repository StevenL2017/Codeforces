#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD
#define endl '\n'

#define ll long long
#define vi vector<int>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)

void solve() {
    int n; cin >> n;
    vector<vi> nodes(n, vi(2));
    vector<vi> graph(n);
    rep(i, n) {
        cin >> nodes[i][0] >> nodes[i][1];
    }
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    function<vector<ll>(int, int)> dfs = [&](int cur, int fa) -> vector<ll> {
        vector<ll> ans(2, 0);
        for (auto& nxt: graph[cur]) {
            if (nxt == fa) continue;
            auto res = dfs(nxt, cur);
            ans[0] += max(res[0] + abs(nodes[cur][0] - nodes[nxt][0]), res[1] + abs(nodes[cur][0] - nodes[nxt][1]));
            ans[1] += max(res[0] + abs(nodes[cur][1] - nodes[nxt][0]), res[1] + abs(nodes[cur][1] - nodes[nxt][1]));
        }
        return ans;
    };
    vector<ll> ans = dfs(0, -1);
    cout << max(ans[0], ans[1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}