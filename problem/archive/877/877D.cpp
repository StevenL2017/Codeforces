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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int dirs4[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n); in(a);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;

    queue<pair<int, int>> q;
    q.emplace(x1, y1);
    vector<vi> d(n, vi(m, INT_MAX));
    d[x1][y1] = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        rep(i, 4) {
            repa(j, 1, k + 1) {
                auto nr = r + j * dirs4[i][0];
                auto nc = c + j * dirs4[i][1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || a[nr][nc] == '#') {
                    break;
                }
                if (d[nr][nc] <= d[r][c]) {
                    break;
                }
                if (d[nr][nc] == INT_MAX) {
                    d[nr][nc] = d[r][c] + 1;
                    q.emplace(nr, nc);
                }
            }
        }
    }

    cout << (d[x2][y2] < INT_MAX ? d[x2][y2] : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}