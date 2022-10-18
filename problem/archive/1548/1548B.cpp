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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> diff;
    rep(i, n - 1) {
        diff.push_back(abs(a[i + 1] - a[i]));
    }

    int ans = 0;
    map<ll, int> gcds;
    rep(i, n - 1) {
        map<ll, int> cur;
        if (diff[i] != 1) {
            cur[diff[i]] = 1;
            ans = max(ans, 1);
        }
        for (auto& [k, v]: gcds) {
            auto g = gcd(k, diff[i]);
            if (g != 1) {
                cur[g] = max(cur[g], 1 + v);
                ans = max(ans, cur[g]);
            }
        }
        gcds = cur;
    }
    cout << ans + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}