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

const int N = 20;

map<ll, int> cnt[N][N];

void solve() {
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<vector<ll>> a(n, vector<ll>(m));
    rep(i, n) in(a[i]);

    ll ans = 0;
    int half = (n + m - 2) / 2;
    function<void(int, int, int, ll)> dfs1 = [&] (int r, int c, int idx, ll val) {
        if (idx == half) {
            cnt[r][c][val ^ a[r][c]]++;
            return;
        }
        if (r + 1 < n) dfs1(r + 1, c, idx + 1, val ^ a[r][c]);
        if (c + 1 < m) dfs1(r, c + 1, idx + 1, val ^ a[r][c]);
    };
    function<void(int, int, int, ll)> dfs2 = [&] (int r, int c, int idx, ll val) {
        if (idx == (n + m - 2) - half) {
            ans += cnt[r][c][val ^ k];
            return;
        }
        if (r - 1 >= 0) dfs2(r - 1, c, idx + 1, val ^ a[r][c]);
        if (c - 1 >= 0) dfs2(r, c - 1, idx + 1, val ^ a[r][c]);
    };
    dfs1(0, 0, 0, 0);
    dfs2(n - 1, m - 1, 0, 0);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}