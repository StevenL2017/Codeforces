#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;

    deque<pair<int, int>> q;
    set<int> visited;
    rep(i, k) {
        int x;
        cin >> x;
        x--;
        if (!visited.count(x)) {
            q.emplace_back(x, -1);
            visited.insert(x);
        }
    }

    vector<vi> graph(n);
    map<pair<int, int>, int> mp;
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        mp[{u, v}] = i + 1;
        mp[{v, u}] = i + 1;
    }

    set<int> ans;
    while (!q.empty()) {
        int m = ssz(q);
        rep(i, m) {
            auto [node, fa] = q.front();
            q.pop_front();
            for (auto& nxt: graph[node]) {
                if (nxt == fa) continue;
                if (visited.count(nxt)) {
                    ans.insert(mp[{node, nxt}]);
                } else {
                    q.emplace_back(nxt, node);
                    visited.insert(nxt);
                }
            }
        }
    }

    cout << ssz(ans) << endl;
    for (auto& x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}