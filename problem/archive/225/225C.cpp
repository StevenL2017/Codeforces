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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<string> a(n);
    in(a);

    vi cnt(m);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cnt[j] += (int)(a[i][j] == '.');
        }
    }

    // 0: .  1: #
    vector<vector<vi>> f(m + 1, vector<vi>(y + 1, vi(2, 2e9)));
    f[0][0][0] = f[0][0][1] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= y; j++) {
            if (f[i][j][0] < 2e9) {
                if (j < y) f[i + 1][j + 1][0] = min(f[i + 1][j + 1][0], f[i][j][0] + n - cnt[i]);
                if (j >= x && j <= y) f[i + 1][1][1] = min(f[i + 1][1][1], f[i][j][0] + cnt[i]);
            }
            if (f[i][j][1] < 2e9) {
                if (j >= x && j <= y) f[i + 1][1][0] = min(f[i + 1][1][0], f[i][j][1] + n - cnt[i]);
                if (j < y) f[i + 1][j + 1][1] = min(f[i + 1][j + 1][1], f[i][j][1] + cnt[i]);
            }
        }
    }

    int ans = 2e9;
    for (int j = x; j <= y; j++) {
        ans = min(ans, min(f[m][j][0], f[m][j][1]));
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