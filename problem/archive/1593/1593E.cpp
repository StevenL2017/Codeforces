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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, k; cin >> n >> k;
    vector<vi> e(n);
    vi deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    queue<int> q;
    vi vis(n, 0);
    for (int i = 0; i < n; i++) {
        if (deg[i] <= 1) {
            q.push(i);
            vis[i] = 1;
        }
    }

    int ans = n;
    while (!q.empty() && k) {
        int cur = ssz(q);
        ans -= cur;
        k--;
        if (ans == 0 || k == 0) break;
        for (int i = 0; i < cur; i++) {
            int u = q.front();
            q.pop();
            for (auto v : e[u]) {
                deg[v]--;
                if (deg[v] <= 1 && !vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
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