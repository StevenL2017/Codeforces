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
    int r, n; cin >> r >> n;
    vector<array<int, 3>> c(n + 1);
    c[0] = {0, 1, 1};
    rep(i, n) {
        int t, x, y;
        cin >> t >> x >> y;
        c[i + 1] = {t, x, y};
    }

    vector<int> f(n + 1, -INF);
    vector<int> fmax(n + 1, -INF);
    f[0] = fmax[0] = 0;
    repa(i, 1, n + 1) {
        repa(j, max(0, i - 2 * r), i) {
            auto d = abs(c[i][1] - c[j][1]) + abs(c[i][2] - c[j][2]);
            if (c[i][0] - c[j][0] >= d) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        if (i - 2 * r > 0) {
            f[i] = max(f[i], fmax[i - 2 * r] + 1);
        }
        fmax[i] = max(f[i], fmax[i - 1]);
    }

    cout << fmax[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}