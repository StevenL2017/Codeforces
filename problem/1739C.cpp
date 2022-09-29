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
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9 + 7;
const int MOD = 998244353;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.begin(), v.end(), greater<auto>())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

ll c[61][61];
ll memo[61];

ll dfs(int x) {
    if (x == 0) {
        return 0;
    }
    if (memo[x] != -1) {
        return memo[x];
    }
    ll ans = 0LL;
    ans += c[x - 1][x / 2];
    ans __;
    ans += (c[x - 2][(x - 2) / 2] - dfs(x - 2) - 1 + MOD) % MOD;
    ans __;
    memo[x] = ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;

    memset(memo, -1, sizeof(memo));
    ll ans = dfs(n);
    cout << ans << " " << (c[n][n / 2] - ans - 1 + MOD) % MOD << " " << 1 << "\n";
}

int main() {
    for (int i = 0; i < 61; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}