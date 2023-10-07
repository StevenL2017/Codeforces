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

const int dirs4[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    in(a);

    vector<vi> vis(n, vi(m, 0));
    function<int(int, int)> dfs1 = [&] (int r, int c) -> int {
        if (a[r][c] == '*') return 1;
        vis[r][c] = 1;
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                ans += dfs1(nr, nc);
            }
        }
        return ans;
    };

    vector<vi> cnt(n, vi(m, -1));
    function<void(int, int, int)> dfs2 = [&] (int r, int c, int tot) {
        if (a[r][c] == '*' || cnt[r][c] != -1) return;
        cnt[r][c] = tot;
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                dfs2(nr, nc, tot);
            }
        }
    };

    while (k--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (cnt[r][c] == -1) {
            auto tot = dfs1(r, c);
            dfs2(r, c, tot);
        }
        cout << cnt[r][c] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}