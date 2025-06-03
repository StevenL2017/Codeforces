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
    int n;
    cin >> n;
    vi a(n);
    in(a);

    int mx = -2e9, ans = -1;
    map<int, int> mn, mn_idx, pre, last, left, right;
    for (int i = 0; i < n; i++) {
        if (last.find(a[i]) == last.end()) {
            mn_idx[a[i]] = -1;
            last[a[i]] = -1;
        }
        pre[a[i]] += 1 - (i - 1 - last[a[i]]);
        int cur = pre[a[i]] - mn[a[i]];
        if (cur > mx) {
            mx = cur;
            ans = a[i];
            left[a[i]] = mn_idx[a[i]] + 1;
            right[a[i]] = i;
        }
        if (mn[a[i]] > pre[a[i]] - 1) {
            mn[a[i]] = pre[a[i]] - 1;
            mn_idx[a[i]] = i - 1;
        }
        last[a[i]] = i;
    }
    cout << ans << " " << left[ans] + 1 << " " << right[ans] + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}