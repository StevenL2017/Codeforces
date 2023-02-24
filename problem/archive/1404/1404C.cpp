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
    int n, q; cin >> n >> q;
    vi a(n + 1);
    repa(i, 1, n + 1) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    vi left(q);
    vector<vi> right(n + 1);
    rep(i, q) {
        int x, y; cin >> x >> y;
        left[i] = 1 + x;
        right[n - y].push_back(i);
    }

    vi ans(q);
    vi bit(n + 1, 0);
    int global = 0;
    repa(r, 1, n + 1) {
        if (a[r] >= 0) {
            int pos = 0, cur = global;
            for (int j = 1 << 20; j >= 1; j >>= 1) {
                if (pos + j <= r && cur - bit[pos + j] >= a[r]) {
                    pos += j;
                    cur -= bit[pos];
                }
            }

            global++;
            for (int i = pos + 1; i <= n; i += i & -i) {
                bit[i]++;
            }
        }

        for (auto& idx: right[r]) {
            ans[idx] = global;
            for (int i = left[idx]; i > 0; i -= i & -i) {
                ans[idx] -= bit[i];
            }
        }
    }

    rep(i, q) cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}