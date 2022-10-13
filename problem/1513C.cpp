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

const int MAXN = 2e5 + 1;
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

int c[MAXN][10];

void solve() {
    int n, m;
    cin >> n >> m;

    ll ans = 0LL;
    while (n > 0) {
        ans += c[m][n % 10];
        ans __;
        n /= 10;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    rep(i, MAXN) {
        rep(j, 10) {
            if (i < 10 - j) {
                c[i][j] = 1;
            } else {
                c[i][j] = c[i - (10 - j)][1] + c[i - (10 - j)][0];
                c[i][j] __;
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}