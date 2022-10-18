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

const int MAXN = 1e6 + 3;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi cnt(2 * k + 1, 0);
    rep(i, n / 2) {
        cnt[a[i] + a[n - i - 1]]++;
    }

    vi pre(2 * k + 1, 0);
    rep(i, n / 2) {
        pre[min(a[i], a[n - i - 1]) + 1]++;
        pre[max(a[i], a[n - i - 1]) + k + 1]--;
    }

    repA(i, 1, 2 * k + 1) {
        pre[i] += pre[i - 1];
    }

    int ans = INF;
    repA(i, 2, 2 * k + 1) {
        ans = min(ans, pre[i] - cnt[i] + (n / 2 - pre[i]) * 2);
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