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

const int N = 3e5 + 1;

int a[N], b[N], f[N], ans[N];
pair<int, int> parent[N];

queue<int> q;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        f[i] = 1e9;
    }
    f[n] = 0;
    q.push(n);
    int limit = n;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int v = u - a[u]; v < limit; v++) {
            if (f[v + b[v]] < 1e9) {
                continue;
            }
            f[v + b[v]] = f[u] + 1;
            parent[v + b[v]] = {v, u};
            q.push(v + b[v]);
        }
        limit = min(limit, u - a[u]);
    }

    if (f[0] >= 1e9) {
        cout << -1 << endl;
        return;
    }

    int j = 0;
    for (int i = 0; i != n; i = parent[i].second) {
        ans[++j] = parent[i].first;
    }
    cout << j << endl;
    for (int i = j; i >= 1; i--) {
        cout << ans[i] << " ";
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