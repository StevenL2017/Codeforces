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
    vector<vi> graph(n);
    vector<pair<int, int>> tbd;
    rep(i, m) {
        int t, u, v;
        cin >> t >> u >> v;
        u--; v--;
        if (t) graph[u].push_back(v);
        tbd.emplace_back(u, v);
    }

    vi ord, visited(n, 0);
    function<void(int)> dfs = [&] (int node) {
        visited[node] = 1;
        for (auto& nxt: graph[node]) {
            if (visited[nxt]) continue;
            dfs(nxt);
        }
        ord.push_back(node);
    };
    rep(i, n) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ord.begin(), ord.end());

    vi pos(n);
    int i = 0;
    for (auto& node: ord) {
        pos[node] = i++;
    }

    rep(node, n) {
        for (auto& nxt: graph[node]) {
            if (pos[node] > pos[nxt]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (auto& [x, y]: tbd) {
        if (pos[x] < pos[y]) {
            cout << x + 1 << " " << y + 1 << endl;
        } else {
            cout << y + 1 << " " << x + 1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}