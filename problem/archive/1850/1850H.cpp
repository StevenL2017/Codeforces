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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> e(n);
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        e[a].emplace_back(b, -d);
        e[b].emplace_back(a, d);
    }

    vector<ll> f(n);
    vi vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        queue<int> q;
        q.emplace(i);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            vis[u] = 1;
            for (auto [v, d]: e[u]) {
                if (!vis[v]) {
                    f[v] = f[u] + d;
                    q.emplace(v);
                } else if (f[v] != f[u] + d) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}