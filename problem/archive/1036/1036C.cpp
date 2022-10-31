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

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    ll l, r; cin >> l >> r;

    auto f = [&] (ll x) -> ll {
        vi digits;
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        int n = ssz(digits);

        ll memo[20][4][2];
        memset(memo, -1, sizeof(memo));
        function<ll(int, int, bool)> dfs = [&] (int pos, int cnt, bool bound) -> ll {
            if (pos == 0) {
                return 1;
            }
            if (memo[pos][cnt][bound] != -1) {
                return memo[pos][cnt][bound];
            }

            ll ans = 0;
            int up = bound ? digits[pos - 1] : 9;
            if (cnt == 3) up = 0;
            rep(i, up + 1) {
                ans += dfs(pos - 1, cnt + (i == 0 ? 0 : 1), bound && (i == up));
            }
            memo[pos][cnt][bound] = ans;
            return ans;
        };
        return dfs(n, 0, true);
    };

    cout << f(r) - f(l - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}