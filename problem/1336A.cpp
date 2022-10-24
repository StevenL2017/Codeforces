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
    int n, k;
    cin >> n >> k;
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    vi depth(n, 0);
    function<void(int, int, int)> dfs1 = [&] (int node, int fa, int d) {
        depth[node] = d;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            dfs1(nxt, node, d + 1);
        }
    };
    dfs1(0, -1, 0);

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return depth[i] > depth[j]; });

    vector<bool> indus(n, false);
    rep(i, k) {
        indus[idx[i]] = true;
    }

    function<vi(int, int)> dfs2 = [&] (int node, int fa) -> vi {
        vi ans(2, 0);
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            auto temp = dfs2(nxt, node);
            ans[0] += temp[0];
            ans[1] += temp[1];
        }
        if (indus[node]) {
            ans[1]++;
        } else {
            ans[0] += ans[1];
        }
        return ans;
    };
    cout << dfs2(0, -1)[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}