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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    in(a);

    vector<vi> vis(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            function<bool(int, int, int, int)> dfs = [&] (int r, int c, int pr, int pc) -> bool {
                if (vis[r][c]) return true;
                vis[r][c] = 1;
                for (int k = 0; k < 4; k++) {
                    int nr = r + dirs4[k][0], nc = c + dirs4[k][1];
                    if (nr == pr && nc == pc) continue;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == a[i][j]) {
                        if (dfs(nr, nc, r, c)) return true;
                    }
                }
                return false;
            };
            if (dfs(i, j, -1, -1)) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}