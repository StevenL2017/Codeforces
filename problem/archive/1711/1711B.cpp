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
    int n, m; cin >> n >> m;
    vi a(n); rep(i, n) cin >> a[i];

    vector<pair<int, int>> f(m);
    vi cnt(n, 0);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        f[i].first = x - 1;
        f[i].second = y - 1;
        cnt[x - 1]++;
        cnt[y - 1]++;
    }

    if (m % 2 == 0) {
        cout << 0 << endl;
        return;
    }
    
    int ans = INF;
    rep(i, n) {
        if (cnt[i] & 1) ans = min(ans, a[i]);
    }
    rep(i, m) {
        int x = f[i].first, y = f[i].second;
        if (cnt[x] % 2 == 0 && cnt[y] % 2 == 0) ans = min(ans, a[x] + a[y]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}