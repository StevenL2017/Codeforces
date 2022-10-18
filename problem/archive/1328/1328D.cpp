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

const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7; // const ll INF = 9e18 + 7;

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
    vi t(n);
    rep(i, n) cin >> t[i];

    if (count(t.begin(), t.end(), t[0]) == n) {
        cout << 1 << endl;
        rep(i, n) cout << 1 << " ";
        cout << endl;
    } else {
        if (n % 2 == 0) {
            cout << 2 << endl;
            rep(i, n) cout << i % 2 + 1 << " ";
            cout << endl;
            return;
        }

        rep(i, n) {
            if (t[i] == t[(i + 1) % n]) {
                vi ans(n);
                for (int j = 0, pos = i + 1; pos < n; pos++, j ^= 1) {
                    ans[pos] = j + 1;
                }
                for (int j = 0, pos = i; pos >= 0; pos--, j ^= 1) {
                    ans[pos] = j + 1;
                }
                cout << 2 << endl;
                rep(i, n) cout << ans[i] << " ";
                cout << endl;
                return;
            }
        }

        cout << 3 << endl;
        rep(i, n - 1) cout << i % 2 + 1 << " ";
        cout << 3 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}