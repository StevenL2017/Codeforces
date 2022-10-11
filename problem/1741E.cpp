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
    int n;
    cin >> n;
    vi b(n);
    rep(i, n) {
        cin >> b[i];
    }

    function<bool(int)> dfs = [&] (int i) -> bool {
        if (i > n) return false;
        if (i == n) return true;
        if (dfs(i + b[i] + 1)) return true;
        int j = i + 1;
        while (j < n) {
            if (b[j] == j - i) {
                if (dfs(j + 1)) return true;
            }
            j++;
        }
        return false;
    };

    bool ans = dfs(0);
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}