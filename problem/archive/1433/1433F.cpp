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

const int N = 75;
int f[N][N][N][N]; // r, c, cnt of selected for current row, remainder

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> mat(n, vi(m));
    rep(i, n) in(mat[i]);
    
    rep(i, N) {
        rep(j, N) {
            rep(c, N) {
                rep(r, N) {
                    f[i][j][c][r] = -INF;
                }
            }
        }
    }
    f[0][0][0][0] = 0;

    rep(i, n) {
        rep(j, m) {
            rep(c, m / 2 + 1) {
                rep(r, k) {
                    if (f[i][j][c][r] == -INF) continue;
                    int ni = (j == m - 1 ? i + 1 : i);
                    int nj = (j == m - 1 ? 0 : j + 1);
                    int nc = (j == m - 1 ? 0 : c);
                    f[ni][nj][nc][r] = max(f[ni][nj][nc][r], f[i][j][c][r]);
                    if (c < m / 2) {
                        nc = (j == m - 1 ? 0 : c + 1);
                        int nr = (r + mat[i][j]) % k;
                        f[ni][nj][nc][nr] = max(f[ni][nj][nc][nr], f[i][j][c][r] + mat[i][j]);
                    }
                }
            }
        }
    }

    cout << max(0, f[n][0][0][0]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}