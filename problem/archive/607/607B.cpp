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
const int INF = 1e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vi c(n); in(c);

    vector<vi> f(n, vi(n, INF));
    repd(i, n - 1, -1) {
        repa(j, i, n) {
            if (i == j) {
                f[i][j] = 1;
                continue;
            }
            if (i + 1 == j) {
                f[i][j] = (c[i] == c[j] ? 1 : 2);
                continue;
            }
            repa(k, i, j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            }
            if (c[i] == c[j]) {
                f[i][j] = min(f[i][j], f[i + 1][j - 1]);
            }
        }
    }

    cout << f[0][n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}