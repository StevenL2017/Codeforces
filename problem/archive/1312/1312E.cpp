#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; ++i)
#define repa(i, a, n)       for (int i = a; i < n; ++i)
#define repd(i, a, n)       for (int i = a; i > n; --i)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;
const long long INF_LL = 9e18 + 7;

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vector<vi> f(n + 1, vi(n + 1, 0));
    function<int(int, int)> dfs = [&] (int l, int r) -> int {
        if (f[l][r] != 0) return f[l][r];
        if (l + 1 == r) {
            f[l][r] = a[l];
            return f[l][r];
        }
        f[l][r] = -1;
        repa(mid, l + 1, r) {
            int left = dfs(l, mid);
            int right = dfs(mid, r);
            if (left > 0 && left == right) {
                f[l][r] = left + 1;
                return f[l][r];
            }
        }
        return f[l][r];
    };

    vi g(n + 1, INF);
    g[0] = 0;
    rep(i, n) {
        repa(j, i + 1, n + 1) {
            if (dfs(i, j) > 0) {
                g[j] = min(g[j], g[i] + 1);
            }
        }
    }

    cout << g[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}