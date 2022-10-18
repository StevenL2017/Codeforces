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
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vi a(n);
    rep(i, n) cin >> a[i];

    vector<vector<bool>> valid(n, vector<bool>(h, false));
    vector<vector<int>> f(n, vector<int>(h, 0));
    valid[0][a[0]] = true;
    valid[0][a[0] - 1] = true;
    f[0][a[0]] = (a[0] >= l && a[0] <= r) ? 1 : 0;
    f[0][a[0] - 1] = (a[0] - 1 >= l && a[0] - 1 <= r) ? 1 : 0;
    repA(i, 1, n) {
        rep(j, h) {
            if (!valid[i - 1][j]) continue;
            int t1 = (j + a[i]) % h, t2 = (j + a[i] - 1 + h) % h;
            valid[i][t1] = true;
            valid[i][t2] = true;
            f[i][t1] = max(f[i][t1], f[i - 1][j] + ((t1 >= l && t1 <= r) ? 1 : 0));
            f[i][t2] = max(f[i][t2], f[i - 1][j] + ((t2 >= l && t2 <= r) ? 1 : 0));
        }
    }
    cout << *max_element(f[n - 1].begin(), f[n - 1].end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}