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
    vi a(n);
    rep(i, n) cin >> a[i];

    int ans = 0, cover = -1;
    vector<vi> f;
    rep(i, n) {
        for (auto& p: f) {
            p[0] = gcd(p[0], a[i]);
        }
        f.push_back({a[i], i, i});
        int cnt = 0, m = f.size();
        rep(j, m) {
            if (cnt > 0 && f[j][0] == f[cnt - 1][0]) {
                f[cnt - 1][2] = f[j][2];
            } else {
                f[cnt++] = f[j];
            }
        }
        f.resize(cnt);
        for (auto& p: f) {
            int at = i - p[0] + 1;
            if (at >= p[1] && at <= p[2]) {
                if (at > cover) {
                    ans++;
                    cover = i;
                }
            }
        }
        cout << ans << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}