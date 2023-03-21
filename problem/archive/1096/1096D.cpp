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
    int n; string s;
    cin >> n >> s;
    vi a(n); in(a);

    string t = "hard";
    vector<vector<ll>> f(n + 1, vector<ll>(5, LLONG_MAX));
    f[0][0] = 0;
    rep(i, n) {
        rep(j, 4) {
            if (f[i][j] == LLONG_MAX) continue;
            f[i + 1][j + (s[i] == t[j])] = min(f[i + 1][j + (s[i] == t[j])], f[i][j]);
            f[i + 1][j] = min(f[i + 1][j], f[i][j] + a[i]);
        }
    }

    ll ans = LLONG_MAX;
    rep(j, 4) {
        ans = min(ans, f[n][j]);
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