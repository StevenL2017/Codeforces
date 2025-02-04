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

struct node {int x1, y1, x2, y2, x3, y3;};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    in(a);

    vector<vi> c(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') {
                c[i][j] = 1;
            }
        }
    }

    vector<node> ans;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j]) {
                ans.push_back({i + 1, j + 1, i + 2, j + 1, i + 2, j + (j == m - 1 ? -1 : 1) + 1});
                c[i][j] ^= 1;
                c[i + 1][j] ^= 1;
                c[i + 1][j + (j == m - 1 ? -1 : 1)] ^= 1;
            }
        }
    }
    for (int j = 0; j < m - 2; j++) {
        if (c[n - 2][j]) {
            ans.push_back({n - 1, j + 1, n - 1, j + 2, n, j + 2});
            c[n - 2][j] ^= 1;
            c[n - 2][j + 1] ^= 1;
            c[n - 1][j + 1] ^= 1;
        }
        if (c[n - 1][j]) {
            ans.push_back({n, j + 1, n - 1, j + 2, n, j + 2});
            c[n - 1][j] ^= 1;
            c[n - 2][j + 1] ^= 1;
            c[n - 1][j + 1] ^= 1;
        }
    }

    node p[4];
    p[0] = {0, 0, 1, 0, 0, 1};
    p[1] = {0, 1, 1, 0, 1, 1};
    p[2] = {0, 0, 0, 1, 1, 1};
    p[3] = {0, 0, 1, 0, 1, 1};
    auto update = [&] (int x, int y, int op, int save) {
        int x1 = x + p[op].x1, x2 = x + p[op].x2, x3 = x + p[op].x3;
        int y1 = y + p[op].y1, y2 = y + p[op].y2, y3 = y + p[op].y3;
        if (!save) {
            c[x1][y1] ^= 1;
            c[x2][y2] ^= 1;
            c[x3][y3] ^= 1;
        } else {
            ans.push_back({x1 + 1, y1 + 1, x2 + 1, y2 + 1, x3 + 1, y3 + 1});
        }
    };
    for (int mask = 0; mask < (1 << 4); mask++) {
        for (int i = 0; i < 4; i++) {
            if (mask >> i & 1) {
                update(n - 2, m - 2, i, 0);
            }
        }
        if (c[n - 2][m - 2] == 0 && c[n - 1][m - 2] == 0 && c[n - 2][m - 1] == 0 && c[n - 1][m - 1] == 0) {
            for (int i = 0; i < 4; i++) {
                if (mask >> i & 1) {
                    update(n - 2, m - 2, i, 1);
                }
            }
            break;
        }
        for (int i = 0; i < 4; i++) {
            if (mask >> i & 1) {
                update(n - 2, m - 2, i, 0);
            }
        }
    }

    cout << ssz(ans) << endl;
    for (auto u: ans) {
        cout << u.x1 << " " << u.y1 << " " << u.x2 << " " << u.y2 << " " << u.x3 << " " << u.y3 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}