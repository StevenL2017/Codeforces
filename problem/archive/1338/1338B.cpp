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
    int n; cin >> n;
    vector<vi> graph(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool even = true;
    function<void(int, int, int)> dfs = [&] (int node, int fa, int d) {
        int cnt = 0;
        for (auto& nxt: graph[node]) {
            if (nxt == fa) continue;
            cnt++;
            dfs(nxt, node, d + 1);
        }
        if (cnt == 0 && d & 1) even = false;
    };

    int root = 0;
    while (ssz(graph[root]) > 1) root++;
    dfs(root, -1, 0);

    int mn = even ? 1 : 3, mx = n - 1;
    vi d(n, 0);
    rep(i, n) if (ssz(graph[i]) == 1) d[graph[i][0]]++;
    rep(i, n) if (d[i] > 0) mx -= d[i] - 1;

    cout << mn << " " << mx << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}