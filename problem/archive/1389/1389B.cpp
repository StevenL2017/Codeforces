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
    int n, k, z;
    cin >> n >> k >> z;
    vi a(n); in(a);

    vi pre(n + 1, 0);
    rep(i, n) {
        pre[i + 1] = pre[i] + a[i];
    }

    int ans = pre[k + 1];
    repa(i, 1, k + 1) {
        int tot = pre[i + 1], res = k - i, left = z;
        while (res > 0 && left > 0) {
            tot += a[i - 1];
            res--; left--;
            ans = max(ans, tot + pre[i + res] - pre[i]);
            if (res > 0) {
                tot += a[i];
                res--;
            }
            ans = max(ans, tot + pre[i + 1 + res] - pre[i + 1]);
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