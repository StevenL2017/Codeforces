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

void solve() {
    int n, x; cin >> n >> x;
    vi a(n); in(a);

    vector<vector<vi>> f(n, vector<vi>(501, vi(501, 1e9)));
    f[0][a[0]][x] = 0;
    if (a[0] > x) f[0][x][a[0]] = 1;
    repa(i, 1, n) {
        rep(j, 501) {
            rep(k, 501) {
                if (f[i - 1][j][k] == 1e9) continue;
                if (a[i] >= j) {
                    f[i][a[i]][k] = min(f[i][a[i]][k], f[i - 1][j][k]);
                }
                if (a[i] > k && k >= j) {
                    f[i][k][a[i]] = min(f[i][k][a[i]], f[i - 1][j][k] + 1);
                }
            }
        }
    }

    int ans = 1e9;
    rep(j, 501) {
        rep(k, 501) {
            ans = min(ans, f[n - 1][j][k]);
        }
    }
    cout << (ans < 1e9 ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}