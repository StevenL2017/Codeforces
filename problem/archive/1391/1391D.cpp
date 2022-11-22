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

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n); in(a);

    if (n >= 4) {
        cout << -1 << endl;
        return;
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    if (n == 2) {
        vector<vi> ok(4, vi(4, 1));
        rep(i, 4) {
            rep(j, 4) {
                int valid = 1;
                rep(k, 1) {
                    int cnt = (bool)(i >> k & 1) + (bool)(i >> (k + 1) & 1);
                    cnt += (bool)(j >> k & 1) + (bool)(j >> (k + 1) & 1);
                    if (cnt % 2 == 0) valid = 0;
                }
                if (!valid) ok[i][j] = 0;
            }
        }
        vector<vi> f(m + 1, vi(4, INF));
        rep(j, 4) f[0][j] = 0;
        rep(i, m) {
            int mask = a[0][i] - '0' + 2 * (a[1][i] - '0');
            rep(cur, 4) {
                rep(pre, 4) {
                    if (!ok[pre][cur]) continue;
                    f[i + 1][cur] = min(f[i + 1][cur], f[i][pre] + __builtin_popcount(cur ^ mask));
                }
            }
        }
        cout << *min_element(f[m].begin(), f[m].end());
    } else {
        vector<vi> ok(8, vi(8, 1));
        rep(i, 8) {
            rep(j, 8) {
                int valid = 1;
                rep(k, 2) {
                    int cnt = (bool)(i >> k & 1) + (bool)(i >> (k + 1) & 1);
                    cnt += (bool)(j >> k & 1) + (bool)(j >> (k + 1) & 1);
                    if (cnt % 2 == 0) valid = 0;
                }
                if (!valid) ok[i][j] = 0;
            }
        }
        vector<vi> f(m + 1, vi(8, INF));
        rep(j, 8) f[0][j] = 0;
        rep(i, m) {
            int mask = a[0][i] - '0' + 2 * (a[1][i] - '0') + 4 * (a[2][i] - '0');
            rep(cur, 8) {
                rep(pre, 8) {
                    if (!ok[pre][cur]) continue;
                    f[i + 1][cur] = min(f[i + 1][cur], f[i][pre] + __builtin_popcount(cur ^ mask));
                }
            }
        }
        cout << *min_element(f[m].begin(), f[m].end());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}