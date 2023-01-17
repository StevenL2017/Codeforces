#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 998244353;

void solve() {
    int n, k; cin >> n >> k;

    vi f(n + 1, 0), ans(n + 1, 0);
    f[0] = 1;
    for (int start = 0; start + k <= n; start += k++) {
        vi s(k);
        for (int i = start; i <= n; i++) {
            int cur = f[i];
            f[i] = s[i % k];
            s[i % k] += cur;
            s[i % k] %= MOD;
            ans[i] += f[i];
            ans[i] %= MOD;
        }
    }

    rep(i, n) cout << ans[i + 1] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}