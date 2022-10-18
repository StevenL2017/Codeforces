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
    int s = 0, odd_idx = 0;
    rep(i, n) {
        cin >> a[i];
        s += a[i];
        if (a[i] % 2 == 1 && odd_idx == 0) {
            odd_idx = i + 1;
        }
    }

    if (s % 2 == 1) {
        cout << 0 << endl;
    } else {
        vector<int> f(s / 2 + 1, 0);
        f[0] = 1;
        rep(i, n) {
            repD(j, s / 2, 0) {
                if (j >= a[i]) f[j] |= f[j - a[i]];
            }
        }
        if (f.back() == 0) {
            cout << 0 << endl;
            return;
        }

        if (odd_idx > 0) {
            cout << 1 << endl;
            cout << odd_idx << endl;
            return;
        }

        int minb = 2001, idx = 0;
        rep(i, n) {
            if ((a[i] & -a[i]) < minb) {
                minb = a[i] & -a[i];
                idx = i + 1;
            }
        }
        cout << 1 << endl;
        cout << idx << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}