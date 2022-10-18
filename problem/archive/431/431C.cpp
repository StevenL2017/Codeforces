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
    int n, k, d;
    cin >> n >> k >> d;

    vector<ll> f(n + 1, 0), g(n + 1, 0);
    f[0] = 1, g[0] = 1;
    for (int j = 1; j < n + 1; j++) {
        for (int i = 1; i <= k; i++) {
            if (j - i >= 0) {
                f[j] += f[j - i];
                f[j] __;
            }
        }
        for (int i = 1; i < d; i++) {
            if (j - i >= 0) {
                g[j] += g[j - i];
                g[j] __;
            }
        }
    }
    cout << (f[n] - g[n] + MOD) _ << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}