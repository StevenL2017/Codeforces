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
    vi a(n); in(a);

    int d = min(n, (int)sqrt(1e5 + 1));
    vector<vi> pre(d, vi(n + 1, 0));
    map<int, vi> idx;
    for (int i = 0; i < n; i++) {
        if (a[i] < d) {
            pre[a[i]][i + 1]++;
        } else {
            idx[a[i]].push_back(i + 1);
        }
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][j + 1] += pre[i][j];
        }
    }
    vi big;
    for (auto [k, v]: idx) {
        if (ssz(v) >= d) {
            big.push_back(k);
        }
    }

    while (m--) {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        for (int i = 1; i < d; i++) {
            int cur = pre[i][r] - pre[i][l - 1];
            if (cur == i) {
                ans++;
            }
        }
        for (auto large: big) {
            int left = lower_bound(idx[large].begin(), idx[large].end(), l) - idx[large].begin();
            int right = upper_bound(idx[large].begin(), idx[large].end(), r) - idx[large].begin();
            if (right - left == large) {
                ans++;
            }
        }

        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}