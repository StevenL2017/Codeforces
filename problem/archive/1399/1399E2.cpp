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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n; ll s;
    cin >> n >> s;
    vector<vi> graph(n);
    vector<vector<ll>> weight(n);
    vector<vi> cost(n);
    rep(i, n - 1) {
        int u, v, c; ll w;
        cin >> u >> v >> w >> c;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        weight[u].push_back(w);
        weight[v].push_back(w);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }

    ll tot1 = 0, tot2 = 0;
    priority_queue<vector<ll>, vector<vector<ll>>> q1, q2;
    function<int(int, int, ll, int)> dfs = [&] (int node, int fa, ll w, int c) -> int {
        int leaves = 0, child = 0;
        rep(i, ssz(graph[node])) {
            auto nxt = graph[node][i];
            if (nxt == fa) continue;
            leaves += dfs(nxt, node, weight[node][i], cost[node][i]);
            child++;
        }
        if (child == 0) leaves = 1;
        if (fa != -1) {
            if (c == 1) {
                tot1 += w * leaves;
                q1.push({w * leaves - (w / 2) * leaves, w, leaves});
            } else {
                tot2 += w * leaves;
                q2.push({w * leaves - (w / 2) * leaves, w, leaves});
            }
        }
        return leaves;
    };
    dfs(0, -1, 0, 0);

    auto calc = [&] (priority_queue<vector<ll>, vector<vector<ll>>>& q, int c, ll tot) -> vector<ll> {
        vector<ll> ans;
        ans.push_back(tot);
        while (tot > 0 && !q.empty()) {
            auto p = q.top();
            q.pop();
            auto d = p[0], w = p[1], c = p[2];
            tot -= d;
            w /= 2;
            ans.push_back(tot);
            q.push({w * c - (w / 2) * c, w, c});
        }
        return ans;
    };
    auto v1 = calc(q1, 1, tot1), v2 = calc(q2, 2, tot2);

    int ans = INT_MAX, j = ssz(v2) - 1;
    rep(i, ssz(v1)) {
        while (j > 0 && v1[i] + v2[j - 1] <= s) j--;
        if (v1[i] + v2[j] <= s) ans = min(ans, i + j * 2);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}