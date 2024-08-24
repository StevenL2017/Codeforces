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
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    auto check = [&] (int r, int c) -> bool {
        if (r < 0 || r >= n - 1 || c < 0 || c >= m - 1) return false;
        int x = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (a[r + i][c + j]) {
                    if (x != 0 && x != a[r + i][c + j]) {
                        return false;
                    }
                    x = a[r + i][c + j];
                }
            }
        }
        if (!x) return false;
        return true;
    };

    queue<int> q;
    vector<vi> vis(n, vi(m, 0));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (check(i, j) && !vis[i][j]) {
                q.push(i * m + j);
                vis[i][j] = 1;
            }
        }
    }

    if (q.empty()) {
        cout << -1 << endl;
        return;
    }

    vector<vi> ans;
    while (!q.empty()) {
        auto k = q.front();
        int r = k / m, c = k % m;
        q.pop();
        int x = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (a[r + i][c + j]) {
                    x = a[r + i][c + j];
                }
            }
        }
        if (x) ans.push_back({r + 1, c + 1, x});
        a[r][c] = a[r + 1][c] = a[r][c + 1] = a[r + 1][c + 1] = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (check(r + i, c + j) && !vis[r + i][c + j]) {
                    q.push((r + i) * m + (c + j));
                    vis[r + i][c + j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << ssz(ans) << endl;
    for (int i = ssz(ans) - 1; i >= 0; i--) {
        out(ans[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}