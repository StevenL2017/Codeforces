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
    int h, c, t;
    cin >> h >> c >> t;

    if (h + c >= 2 * t) {
        cout << 2 << endl;
        return;
    }

    int x = (t - c) / (2 * t - h - c);
    ll t1 = abs(1LL * t * (2 * x - 1) - (1LL * h * x + 1LL * c * (x - 1)));
    ll t2 = abs(1LL * t * (2 * x + 1) - (1LL * h * (x + 1) + 1LL * c * (x)));
    if (t1 * (2 * x + 1) > t2 * (2 * x - 1)) x++;
    cout << 2 * x - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}