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
    vector<string> a(n);
    in(a);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '-') {
                continue;
            }
            function<void(int, int, int)> dfs = [&] (int r, int c, int color) {
                a[r][c] = (color ? 'W' : 'B');
                for (auto [nr, nc]: vector<pair<int, int>>{{r - 1, c}, {r + 1, c}, {r, c - 1}, {r, c + 1}}) {
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && a[nr][nc] == '.') {
                        dfs(nr, nc, color ^ 1);
                    }
                }
            };
            if (a[i][j] == '.') {
                dfs(i, j, 0);
            }
        }
    }

    for (auto row : a) {
        cout << row << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}