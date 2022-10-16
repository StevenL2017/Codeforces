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
    vi p(n);
    rep(i, n) cin >> p[i];

    map<int, int> mp;
    rep(i, n) {
        mp[p[i]] = i;
    }

    int ans = 1;
    int left = mp[0], right = mp[0];
    repA(x, 1, n) {
        left = min(left, mp[x - 1]);
        right = max(right, mp[x - 1]);
        if (mp[x] > left && mp[x] < right) {
            continue;
        } else {
            if (right - left + 1 > 2 * x - 1) {
                continue;
            }
            if (mp[x] < left) {
                int left_limit = max(mp[x], right - 2 * x) + 1;
                int right_limit = min(n - 1, left + 2 * x - 1);
                if (left - left_limit <= right_limit - right) {
                    int left_cnt = left - left_limit + 1;
                    int right_cnt = left_limit + 2 * x - 1 - right + 1;
                    int m = right_limit - right + 1 - right_cnt;
                    ans += left_cnt * right_cnt + m;
                } else {
                    int right_cnt = right_limit - right + 1;
                    int left_cnt = right_limit - 2 * x + 1 - left + 1;
                    int m = left - left_limit + 1 - left_cnt;
                    ans += left_cnt * right_cnt + m;
                }
            } else {
                int left_limit = max(0, right - 2 * x + 1);
                int right_limit = min(mp[x], left + 2 * x) - 1;
                if (left - left_limit <= right_limit - right) {
                    int left_cnt = left - left_limit + 1;
                    int right_cnt = left_limit + 2 * x - 1 - right + 1;
                    int m = right_limit - right + 1 - right_cnt;
                    ans += left_cnt * right_cnt + m;
                } else {
                    int right_cnt = right_limit - right + 1;
                    int left_cnt = right_limit - 2 * x + 1 - left + 1;
                    int m = left - left_limit + 1 - left_cnt;
                    ans += left_cnt * right_cnt + m;
                }
            }
        }
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