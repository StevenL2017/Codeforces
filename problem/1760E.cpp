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

    vi pre0(n + 1, 0), pre1(n + 1, 0);
    vi suf0(n + 1, 0), suf1(n + 1, 0);
    rep(i, n) {
        if (a[i] == 0) {
            pre0[i + 1] = pre0[i] + 1;
            pre1[i + 1] = pre1[i];
        } else {
            pre0[i + 1] = pre0[i];
            pre1[i + 1] = pre1[i] + 1;
        }
    }
    repd(i, n - 1, -1) {
        if (a[i] == 0) {
            suf0[i] = suf0[i + 1] + 1;
            suf1[i] = suf1[i + 1];
        } else {
            suf0[i] = suf0[i + 1];
            suf1[i] = suf1[i + 1] + 1;
        }
    }

    ll temp = 0;
    rep(i, n) {
        if (a[i] == 1) temp += 1ll * suf0[i + 1];
    }

    ll ans = temp;
    rep(i, n) {
        if (a[i] == 0) {
            ans = max(ans, temp - pre1[i] + suf0[i + 1]);
        } else {
            ans = max(ans, temp - suf0[i + 1] + pre1[i]);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}