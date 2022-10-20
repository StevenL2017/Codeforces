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
    int m, n; cin >> m >> n;
    vector<vi> p(m, vi(n));
    rep(i, m) {
        rep(j, n) cin >> p[i][j];
    }

    auto check = [&] (int x) -> bool {
        bool ans = false;
        vector<bool> visited(m, false);
        rep(i, n) {
            bool found = false;
            rep(j, m) {
                if (p[j][i] >= x) {
                    found = true;
                    if (visited[j]) ans = true;
                    visited[j] = true;
                }
            }
            if (!found) return false;
        }
        return ans;
    };

    int left = 1, right = 1e9;
    int ans = left;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
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