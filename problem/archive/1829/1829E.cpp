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

const int dirs4[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void solve() {
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    int ans = 0;
    function<int(int, int)> dfs = [&] (int r, int c) -> int {
        if (r < 0 || r >= n || c < 0 || c >= m || a[r][c] == 0) {
            return 0;
        }
        int cur = a[r][c];
        a[r][c] = 0;
        for (auto [dr, dc] : dirs4) {
            int nr = r + dr, nc = c + dc;
            cur += dfs(nr, nc);
        }
        return cur;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                ans = max(ans, dfs(i, j));
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