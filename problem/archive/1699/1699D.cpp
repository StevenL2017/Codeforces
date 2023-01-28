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

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vector<vector<bool>> d(n, vector<bool>(n, true));
    rep(i, n) {
        vi cnt(n + 1, 0);
        int mx = 0;
        repa(j, i, n) {
            cnt[a[j]]++;
            mx = max(mx, cnt[a[j]]);
            if (((j - i + 1) & 1) || mx > ((j - i + 1) / 2)) {
                d[i][j] = false;
            }
        }
    }

    vi f(n, 0);
    rep(i, n) {
        if (i == 0 || d[0][i - 1]) {
            f[i] = 1;
        }
        rep(j, i) {
            if (f[j] && d[j + 1][i - 1] && a[j] == a[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    
    int ans = f[n - 1];
    repd(i, n - 2, -1) {
        if (d[i + 1][n - 1]) {
            ans = max(ans, f[i]);
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