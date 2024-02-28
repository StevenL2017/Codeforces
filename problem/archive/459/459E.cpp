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

const int N = 3e5 + 3;

vector<pair<int, int>> e[N];
int f[N], tmp[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[w].emplace_back(u, v);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < ssz(e[i]); j++) {
            int u = e[i][j].first, v = e[i][j].second;
            tmp[v] = 0;
        }
        for (int j = 0; j < ssz(e[i]); j++) {
            int u = e[i][j].first, v = e[i][j].second;
            tmp[v] = max(tmp[v], f[u] + 1);
        }
        for (int j = 0; j < ssz(e[i]); j++) {
            int u = e[i][j].first, v = e[i][j].second;
            f[v] = max(f[v], tmp[v]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i]);
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