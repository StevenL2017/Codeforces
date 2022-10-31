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
    int n; cin >> n;
    vector<set<int>> graph(n);
    rep(i, n - 1) {
        int x, y; cin >> x >> y;
        x--; y--;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    queue<int> q;
    vector<bool> visited(n, false);
    q.push(0);
    visited[0] = true;
    int start = 1;
    while (!q.empty()) {
        int m = ssz(q);
        rep(i, m) {
            auto cur = q.front();
            q.pop();
            for (int j = start; j < start + ssz(graph[cur]) - (cur == 0 ? 0 : 1); j++) {
                if (graph[cur].find(a[j]) == graph[cur].end() || visited[a[j]]) {
                    cout << "No\n";
                    return;
                }
                q.push(a[j]);
                visited[a[j]] = true;
            }
            start += ssz(graph[cur]) - (cur == 0 ? 0 : 1);
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}