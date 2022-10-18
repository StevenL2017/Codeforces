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
    int n;
    cin >> n;
    vi a(n);
    ll s = 0LL;
    for (auto& x: a) {
        cin >> x;
        s += x;
    }

    if (n < 3 || s % 3 != 0) {
        cout << 0 << endl;
        return;
    }

    ll t = s / 3, suf = 0LL;
    map<int, int> cnt;
    repD(i, n - 1, 0) {
        suf += a[i];
        if (i < n - 1) {
            cnt[i] = cnt[i + 1];
        }
        if (suf == t) {
            cnt[i]++;
        }
    }

    ll ans = 0LL, pre = 0LL;
    rep(i, n - 2) {
        pre += a[i];
        if (pre == t) {
            ans += cnt[i + 2];
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