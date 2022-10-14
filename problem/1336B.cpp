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
const ll INF = 9e18 + 7;

#define _  %  MOD
#define __ %= MOD

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.rbegin(), v.rend())

#define rep(i, n)              for (int i = 0; i < n; ++i)
#define repA(i, a, n)          for (int i = a; i < n; ++i)
#define repD(i, a, n)          for (int i = a; i > n; --i)
#define loop(i, start, end)    for (auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

ll calc(ll x, ll y, ll z) {
    return (x - y) * (x - y) + (z - y) * (z - y) + (x - z) * (x - z);
}

ll check(vector<ll> x, vector<ll> y, vector<ll> z) {
    ll ans = INF;
    for (auto& num: x) {
        int left = lower_bound(y.begin(), y.end(), num) - y.begin();
        int right = upper_bound(z.begin(), z.end(), num) - z.begin();
        if (left == y.size() || right == 0) continue;
        ans = min(ans, calc(num, y[left], z[right - 1]));
    }
    return ans;
}

void solve() {
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    vector<ll> r(nr), g(ng), b(nb);
    rep(i, nr) cin >> r[i];
    rep(i, ng) cin >> g[i];
    rep(i, nb) cin >> b[i];

    sortA(r);
    sortA(g);
    sortA(b);
    ll ans = INF;
    ans = min(ans, check(r, g, b));
    ans = min(ans, check(r, b, g));
    ans = min(ans, check(g, r, b));
    ans = min(ans, check(g, b, r));
    ans = min(ans, check(b, r, g));
    ans = min(ans, check(b, g, r));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}