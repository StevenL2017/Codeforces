#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, map<int, int>> graph;
    rep(i, n) {
        rep(j, m - 1) {
            int w; cin >> w;
            int u = i * m + j;
            int v = i * m + j + 1;
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }
    rep(i, n - 1) {
        rep(j, m) {
            int w; cin >> w;
            int u = i * m + j;
            int v = (i + 1) * m + j;
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    if (k & 1) {
        rep(i, n) {
            rep(j, m) {
                cout << -1 << " ";
            }
            cout << endl;
        }
        return;
    }

    k /= 2;
    vector<vector<vi>> f(n, vector<vi>(m, vi(k + 1, INF)));
    rep(i, n) {
        rep(j, m) {
            f[i][j][0] = 0;
        }
    }
    repA(c, 1, k + 1) {
        rep(i, n) {
            rep(j, m) {
                f[i][j][0] = 0;
                int v = i * m + j;
                if (i > 0 && j > 0) {
                    int up = (i - 1) * m + j, left = i * m + j - 1;
                    f[i][j][c] = min(f[i][j][c], f[i - 1][j][c - 1] + graph[up][v]);
                    f[i][j][c] = min(f[i][j][c], f[i][j - 1][c - 1] + graph[left][v]);
                }
                else if (i > 0) {
                    int up = (i - 1) * m + j;
                    f[i][j][c] = min(f[i][j][c], f[i - 1][j][c - 1] + graph[up][v]);
                }
                else if (j > 0) {
                    int left = i * m + j - 1;
                    f[i][j][c] = min(f[i][j][c], f[i][j - 1][c - 1] + graph[left][v]);
                }
            }
        }
        repD(i, n - 1, -1) {
            repD(j, m - 1, -1) {
                int v = i * m + j;
                if (i < n - 1 && j < m - 1) {
                    int down = (i + 1) * m + j, right = i * m + j + 1;
                    f[i][j][c] = min(f[i][j][c], f[i + 1][j][c - 1] + graph[down][v]);
                    f[i][j][c] = min(f[i][j][c], f[i][j + 1][c - 1] + graph[right][v]);
                }
                else if (i < n - 1) {
                    int down = (i + 1) * m + j;
                    f[i][j][c] = min(f[i][j][c], f[i + 1][j][c - 1] + graph[down][v]);
                }
                else if (j < m - 1) {
                    int right = i * m + j + 1;
                    f[i][j][c] = min(f[i][j][c], f[i][j + 1][c - 1] + graph[right][v]);
                }
            }
        }
    }

    rep(i, n) {
        rep(j, m) {
            cout << f[i][j][k] * 2 << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}