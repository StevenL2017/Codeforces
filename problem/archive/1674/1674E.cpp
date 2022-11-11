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

    int mn1 = INF, mn2 = INF;
    rep(i, n) {
        if (a[i] < mn1) {
            mn2 = mn1;
            mn1 = a[i];
        }
        else if (a[i] < mn2) {
            mn2 = a[i];
        }
    }

    int ans = (mn1 + 1) / 2 + (mn2 + 1) / 2;
    rep(i, n) {
        if (i == 0) {
            if (a[i] <= a[i + 1] / 2 || a[i + 1] <= a[i] / 2) ans = min(ans, (max(a[i], a[i + 1]) + 1) / 2);
            else ans = min(ans, (a[i] + a[i + 1] + 3 - 1) / 3);
        }
        else if (i == n - 1) {
            if (a[i] <= a[i - 1] / 2 || a[i - 1] <= a[i] / 2) ans = min(ans, (max(a[i], a[i - 1]) + 1) / 2);
            else ans = min(ans, (a[i] + a[i - 1] + 3 - 1) / 3);
        }
        else {
            if (a[i] <= a[i + 1] / 2 || a[i + 1] <= a[i] / 2) ans = min(ans, (max(a[i], a[i + 1]) + 1) / 2);
            else ans = min(ans, (a[i] + a[i + 1] + 3 - 1) / 3);
            if (a[i] <= a[i - 1] / 2 || a[i - 1] <= a[i] / 2) ans = min(ans, (max(a[i], a[i - 1]) + 1) / 2);
            else ans = min(ans, (a[i] + a[i - 1] + 3 - 1) / 3);
            ans = min(ans, min(a[i - 1], a[i + 1]) + (abs(a[i - 1] - a[i + 1]) + 1) / 2);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}