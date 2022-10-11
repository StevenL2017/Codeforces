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
    int m;
    cin >> m;
    vi p(m);
    rep(i, m) {
        cin >> p[i];
    }

    function<int(int, int)> merge = [&] (int left, int right) -> int {
        int mid = left + (right - left) / 2;
        if (right - left == 1) return 0;
        int lc = merge(left, mid);
        int rc = merge(mid, right);
        if (lc == INF || rc == INF) return INF;
        if (abs(p[left] - p[mid]) != mid - left) return INF;
        if (p[left] > p[mid]) {
            for (int i = 0; i < mid - left; i++) {
                swap(p[i + left], p[i + mid]);
            }
            return lc + rc + 1;
        }
        else return lc + rc;
    };

    int ans = merge(0, m);
    cout << (ans < INF ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}