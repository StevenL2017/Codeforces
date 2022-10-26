#include <iostream>
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
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD
#define endl '\n'

#define ll long long
#define vi vector<int>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)

void solve() {
    int n; cin >> n;
    vi t(n);
    rep(i, n) cin >> t[i];

    sortA(t);
    vector<vi> f(n + 1, vi(2 * n + 1, INF));
    rep(j, 2 * n + 1) f[0][j] = 0;
    repA(i, 1, n + 1) {
        repA(j, 1, 2 * n + 1) {
            f[i][j] = min(f[i][j - 1], f[i - 1][j - 1] + abs(j - t[i - 1]));
        }
    }

    int ans = INF;
    rep(j, 2 * n + 1) ans = min(ans, f[n][j]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}