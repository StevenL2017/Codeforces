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

map<int, bool> memo;

bool dfs(int x) {
    if (x == 1) return false;
    if (memo.find(x) != memo.end()) return memo[x];
    int d = 2;
    while (d * d <= x) {
        if (x % d == 0) {
            if (!dfs(x - d) || !dfs(x - x / d)) {
                memo[x] = true;
                return true;
            }
        }
        d++;
    }
    memo[x] = false;
    return false;
}

void solve() {
    int n;
    cin >> n;

    bool ans = dfs(n);
    cout << (ans ? "Alice" : "Bob") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}