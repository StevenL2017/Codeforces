#include <iostream>
#include <cstdio>
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
#include <random>

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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> mat(n); in(mat);
    
    vector<vector<vi>> pre(n, vector<vi>(m, vi(8, 1)));
    repa(i, 1, n) {
        rep(j, m) {
            if (j > 0 && mat[i][j] == mat[i - 1][j - 1]) pre[i][j][0] = pre[i - 1][j - 1][0] + 1;
            if (mat[i][j] == mat[i - 1][j]) pre[i][j][1] = pre[i - 1][j][1] + 1;
        }
    }
    rep(i, n) {
        repd(j, m - 2, -1) {
            if (i > 0 && mat[i][j] == mat[i - 1][j + 1]) pre[i][j][2] = pre[i - 1][j + 1][2] + 1;
            if (mat[i][j] == mat[i][j + 1]) pre[i][j][3] = pre[i][j + 1][3] + 1;
        }
    }
    repd(i, n - 2, -1) {
        repd(j, m - 1, -1) {
            if (j < m - 1 && mat[i][j] == mat[i + 1][j + 1]) pre[i][j][4] = pre[i + 1][j + 1][4] + 1;
            if (mat[i][j] == mat[i + 1][j]) pre[i][j][5] = pre[i + 1][j][5] + 1;
        }
    }
    repd(i, n - 1, -1) {
        repa(j, 1, m) {
            if (i < n - 1 && mat[i][j] == mat[i + 1][j - 1]) pre[i][j][6] = pre[i + 1][j - 1][6] + 1;
            if (mat[i][j] == mat[i][j - 1]) pre[i][j][7] = pre[i][j - 1][7] + 1;
        }
    }

    ll ans = 0;
    rep(i, n) {
        rep(j, m) {
            auto mn1 = min({pre[i][j][1], pre[i][j][3], pre[i][j][5], pre[i][j][7]});
            auto mn2 = min({pre[i][j][0], pre[i][j][2], pre[i][j][4], pre[i][j][6]});
            ans += min(mn1, mn2 * 2);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}