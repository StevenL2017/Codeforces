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

const int MOD = 1e8;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

ll f[101][101][11][11];

void solve() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    memset(f, -1, sizeof(f));
    function<ll(int, int, int, int)> dfs = [&] (int x1, int x2, int c1, int c2) -> ll {
        if (x1 == n1 && x2 == n2) {
            return 1;
        }
        if (f[x1][x2][c1][c2] != -1) {
            return f[x1][x2][c1][c2];
        }
        ll ans = 0;
        if (x1 < n1 && c1 < k1) {
            ans += dfs(x1 + 1, x2, c1 + 1, 0);
            ans %= MOD;
        }
        if (x2 < n2 && c2 < k2) {
            ans += dfs(x1, x2 + 1, 0, c2 + 1);
            ans %= MOD;
        }
        f[x1][x2][c1][c2] = ans;
        return ans;
    };

    cout << dfs(0, 0, 0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}