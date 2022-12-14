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

const int MAXN = 1e5 + 1;
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
    int t, k;
    cin >> t >> k;
    vector<ll> f(MAXN, 0);
    f[0] = 1;
    repA(i, 1, MAXN) {
        f[i] = f[i - 1];
        if (i - k >= 0) {
            f[i] += f[i - k];
            f[i] __;
        }
    }
    vector<ll> pre;
    pre.push_back(0);
    for (auto& x: f) {
        pre.push_back(pre.back() + x);
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (pre[b + 1] - pre[a] + MOD) _ << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}