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

    int ans = 0, mask = 0;
    for (int sub = 0; sub < (1 << n); sub++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (sub >> i & 1) {
                int j = i;
                while (j + 1 < n && sub >> (j + 1) & 1) {
                    j++;
                }
                cur += (j - i + 1) * (j - i + 1);
                i = j;
            } else {
                cur += a[i];
            }
        }
        if (cur > ans) {
            ans = cur;
            mask = sub;
        }
    }

    vector<pair<int, int>> idx;
    function<void(int, int)> operate = [&] (int l, int r) {
        vi cnt(n + 1);
        for (int i = l; i <= r; i++) {
            if (a[i] <= n) {
                cnt[a[i]]++;
            }
        }
        int mex = 0;
        while (cnt[mex]) {
            mex++;
        }
        for (int i = l; i <= r; i++) {
            a[i] = mex;
        }
        idx.emplace_back(l + 1, r + 1);
    };
    function<void(int, int)> build = [&] (int l, int r) {
        if (l == r) {
            if (a[l]) {
                operate(l, r);
            }
            return;
        }
        build(l, r - 1);
        if (a[r] != r - l) {
            operate(l, r);
            build(l, r - 1);
        }
    };

    for (int i = 0; i < n; i++) {
        if (mask >> i & 1) {
            int j = i;
            while (j + 1 < n && mask >> (j + 1) & 1) {
                j++;
            }
            build(i, j);
            operate(i, j);
            i = j;
        }
    }

    cout << ans << " " << ssz(idx) << endl;
    for (auto [l, r]: idx) {
        cout << l << " " << r << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}