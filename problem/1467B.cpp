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
    vi a(n);
    rep(i, n) cin >> a[i];

    if (n <= 3) {
        cout << 0 << endl;
        return;
    }

    int tot = 0, cnt = 0;
    loop(i, 1, n - 1) {
        if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) {
            tot++;
            int d = 0;
            if (i == 1) {
                if ((a[i + 1] > a[i] && a[i + 1] > a[i + 2]) || (a[i + 1] < a[i] && a[i + 1] < a[i + 2])) {
                    d = 2;
                } else {
                    d = 1;
                }
            }
            else if (i == n - 2) {
                if ((a[i - 1] > a[i] && a[i - 1] > a[i - 2]) || (a[i - 1] < a[i] && a[i - 1] < a[i - 2])) {
                    d = 2;
                } else {
                    d = 1;
                }
            }
            else {
                int pre = ((a[i - 1] > a[i] && a[i - 1] > a[i - 2]) || (a[i - 1] < a[i] && a[i - 1] < a[i - 2])) ? 1 : 0;
                int nxt = ((a[i + 1] > a[i] && a[i + 1] > a[i + 2]) || (a[i + 1] < a[i] && a[i + 1] < a[i + 2])) ? 1 : 0;
                // i value => i - 1 value
                int nxt_new = ((a[i + 1] > a[i - 1] && a[i + 1] > a[i + 2]) || (a[i + 1] < a[i - 1] && a[i + 1] < a[i + 2])) ? 1 : 0;
                // i value => i + 1 value
                int pre_new = ((a[i - 1] > a[i + 1] && a[i - 1] > a[i - 2]) || (a[i - 1] < a[i + 1] && a[i - 1] < a[i - 2])) ? 1 : 0;
                d = 1 + pre + nxt - min(nxt_new, pre_new);
            }
            cnt = max(cnt, d);
        }
    }
    cout << tot - cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}