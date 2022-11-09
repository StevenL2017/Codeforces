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

const int dirs4[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n); in(mat);

    bool has_black = false;
    vector<bool> row_white(n, true);
    vector<bool> col_white(m, true);
    rep(i, n) {
        rep(j, m) {
            if (mat[i][j] == '#') {
                has_black = true;
                row_white[i] = false;
                col_white[j] = false;
            }
        }
    }

    if (!has_black) {
        cout << 0 << endl;
        return;
    }

    rep(i, n) {
        if (row_white[i]) {
            bool valid = false;
            rep(j, m) {
                if (col_white[j]) {
                    valid = true;
                    break;
                }
            }
            if (valid) continue;
            else {
                cout << -1 << endl;
                return;
            }
        }

        int j = 0, k = m - 1;
        while (j < m && mat[i][j] == '.') {
            j++;
        }
        while (k >= 0 && mat[i][k] == '.') {
            k--;
        }
        repa(c, j + 1, k) {
            if (mat[i][c] == '.') {
                cout << -1 << endl;
                return;
            }
        }
    }
    rep(j, m) {
        if (col_white[j]) {
            bool valid = false;
            rep(i, n) {
                if (row_white[i]) {
                    valid = true;
                    break;
                }
            }
            if (valid) continue;
            else {
                cout << -1 << endl;
                return;
            }
        }

        int i = 0, k = n - 1;
        while (i < n && mat[i][j] == '.') {
            i++;
        }
        while (k >= 0 && mat[k][j] == '.') {
            k--;
        }
        repa(c, i + 1, k) {
            if (mat[c][j] == '.') {
                cout << -1 << endl;
                return;
            }
        }
    }

    int ans = 0;
    vi visited(n * m, 0);
    function<void(int, int, int)> dfs = [&] (int r, int c, int color) {
        visited[r * m + c] = color;
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (mat[nr][nc] == '#' && !visited[nr * m + nc]) {
                    dfs(nr, nc, color);
                }
            }
        }
    };
    rep(i, n) {
        rep(j, m) {
            if (mat[i][j] == '#' && !visited[i * m + j]) {
                ans++;
                dfs(i, j, ans);
            }
        }
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