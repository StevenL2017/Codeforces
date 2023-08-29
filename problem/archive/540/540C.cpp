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
    int n, m; cin >> n >> m;
    vector<string> a(n); in(a);
    int r1, c1; cin >> r1 >> c1;
    r1--; c1--;
    int r2, c2; cin >> r2 >> c2;
    r2--; c2--;

    bool ok = false;
    queue<pair<int, int>> q;
    q.emplace(r1, c1);
    vi vis(n * m, 0);
    vis[r1 * m + c1] = 1;
    while (!q.empty()) {
        auto [r, c] = q.front();
        if (r == r2 && c == c2) {
            ok = true;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if ((nr == r2 && nc == c2) || a[nr][nc] == '.') {
                    if (vis[nr * m + nc] == 0) {
                        q.emplace(nr, nc);
                        vis[nr * m + nc] = 1;
                    }
                }
            }
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    if (a[r2][c2] == 'X' && (r1 != r2 || c1 != c2)) {
        cout << "YES\n";
        return;
    }

    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r2 + dirs4[i][0], nc = c2 + dirs4[i][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
            if (a[nr][nc] == '.' || (nr == r1 && nc == c1)) {
                cnt++;
            }
        }
    }
    if (cnt >= 2 || (cnt == 1 && r1 == r2 && c1 == c2)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}