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
    int n, m; cin >> n >> m;

    auto get_d = [&] (int r, int c) -> int {
        return max({abs(r) + abs(c), abs(r - (n - 1)) + abs(c), abs(r) + abs(c - (m - 1)), abs(r - (n - 1)) + abs(c - (m - 1))});
    };

    vi cnt(n * m, 0);
    rep(r, n) {
        rep(c, m) {
            cnt[get_d(r, c)]++;
        }
    }

    vi ans(n * m, 0);
    int pre = 0, j = 0;
    rep(i, n * m) {
        while (j < n * m && pre <= i) {
            pre += cnt[j++];
        }
        ans[i] = j - 1;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}