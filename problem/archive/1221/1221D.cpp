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
    vi a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<vector<ll>> f(n, vector<ll>(3, INF_LL));
    f[0][0] = 0;
    f[0][1] = 1ll * b[0];
    f[0][2] = 2ll * b[0];
    repa(i, 1, n) {
        rep(j, 3) {
            rep(k, 3) {
                if (a[i] + k != a[i - 1] + j) {
                    f[i][k] = min(f[i][k], f[i - 1][j] + k * 1ll * b[i]);
                }
            }
        }
    }

    cout << *min_element(f[n - 1].begin(), f[n - 1].end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}