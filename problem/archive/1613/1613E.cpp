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
    vector<string> g(n); in(g);

    deque<pair<int, int>> q;
    rep(i, n) {
        rep(j, m) {
            if (g[i][j] == 'L') {
                q.emplace_back(i, j);
                break;
            }
        }
        if (!q.empty()) break;
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        if (g[r][c] == '.') g[r][c] = '+';
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == '.') {
                int cnt = 0;
                for (int j = 0; j < 4; j++) {
                    int nnr = nr + dirs4[j][0], nnc = nc + dirs4[j][1];
                    if (nnr >= 0 && nnr < n && nnc >= 0 && nnc < m && g[nnr][nnc] == '.') {
                        cnt++;
                    }
                }
                if (cnt <= 1) {
                    q.emplace_back(nr, nc);
                }
            }
        }
    }

    rep(i, n) {
        cout << g[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}