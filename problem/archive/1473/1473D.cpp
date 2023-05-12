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
    int n, m; cin >> n >> m;
    string s; cin >> s;

    vi pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            pre[i + 1] = pre[i] + 1;
        } else {
            pre[i + 1] = pre[i] - 1;
        }
    }

    vi pre_mx(n + 1, 0), pre_mn(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre_mx[i + 1] = max(pre_mx[i], pre[i + 1]);
        pre_mn[i + 1] = min(pre_mn[i], pre[i + 1]);
    }

    vi suf_mx(n + 1, INT_MIN), suf_mn(n + 1, INT_MAX);
    for (int i = n - 1; i >= 0; i--) {
        suf_mx[i] = max(suf_mx[i + 1], pre[i + 1]);
        suf_mn[i] = min(suf_mn[i + 1], pre[i + 1]);
    }

    while (m--) {
        int l, r; cin >> l >> r;

        int mx = 0, mn = 0;
        if (r < n) {
            auto d = pre[r] - pre[l - 1];
            mx = max(pre_mx[l - 1], suf_mx[r] - d);
            mn = min(pre_mn[l - 1], suf_mn[r] - d);
        } else {
            mx = pre_mx[l - 1];
            mn = pre_mn[l - 1];
        }
        
        cout << mx - mn + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}