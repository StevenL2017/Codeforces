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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + m + 1), b(n + m + 1);
    in(a);
    in(b);

    vi t(n + m + 1);
    int c1 = 0, c2 = 0, bad = -1, bad_t = -1;
    ll tot = 0;
    for (int i = 0; i < n + m; i++) {
        if (a[i] > b[i] && c1 == n && bad == -1) {
            bad = i;
            bad_t = 1;
        }
        if (a[i] <= b[i] && c2 == m && bad == -1) {
            bad = i;
            bad_t = 0;
        }
        if (c2 == m || c1 < n && a[i] > b[i]) {
            t[i] = 0;
            c1++;
            tot += a[i];
        } else {
            t[i] = 1;
            c2++;
            tot += b[i];
        }
    }

    vector<ll> ans(n + m + 1);
    for (int i = 0; i < n + m; i++) {
        if (i < bad && t[i] != bad_t) {
            ans[i] = tot - (t[i] ? b[i] : a[i]) + (t[i] ? b[bad] : a[bad]) - (bad_t ? b[bad] : a[bad]) + (bad_t ? b[n + m] : a[n + m]);
        } else {
            ans[i] = tot - (t[i] ? b[i] : a[i]) + (t[i] ? b[n + m] : a[n + m]);
        }
    }
    ans[n + m] = tot;

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}