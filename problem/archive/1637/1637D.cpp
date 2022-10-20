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
#include <bitset>
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

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int sum_sq = 0, sum_mn = 0, sum_mx = 0;
    rep(i, n) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        sum_sq += a[i] * a[i] + b[i] * b[i];
        sum_mn += a[i];
        sum_mx += b[i];
    }

    bitset<MAXN> f;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        int w = b[i] - a[i];
        f |= f << w;
    }

    int ans = sum_mn * sum_mn + sum_mx * sum_mx;
    for (int i = 0; i <= sum_mx - sum_mn; i++) {
        if (f[i]) ans = min(ans, (sum_mn + i) * (sum_mn + i) + (sum_mx - i) * (sum_mx - i));
    }
    cout << (n - 2) * sum_sq + ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}