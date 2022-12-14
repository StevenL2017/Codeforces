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

    vector<vector<int>> f(n, vector<int>(m, 1));
    repa(i, 2, n) {
        repa(j, 1, m - 1) {
            if (mat[i][j] == mat[i - 1][j - 1] && 
                mat[i][j] == mat[i - 1][j] && 
                mat[i][j] == mat[i - 1][j + 1] && 
                mat[i][j] == mat[i - 2][j]) {
                f[i][j] = min({f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1], f[i - 2][j]}) + 1;
            }
        }
    }

    ll ans = 0;
    rep(i, n) {
        rep(j, m) {
            ans += f[i][j];
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