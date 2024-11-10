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

    vi pre(n + 1, -1), mx(n + 1, -1);
    for (int i = 0; i < n; i++) {
        mx[a[i]] = max(mx[a[i]], i - pre[a[i]]);
        pre[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        mx[a[i]] = max(mx[a[i]], n - pre[a[i]]);
    }

    vi ans(n, -1), idx(n + 1);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return mx[i] < mx[j]; });
    int mn = 1e9;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && mx[idx[j]] <= i) {
            if (mx[idx[j]] != -1) {
                mn = min(mn, idx[j]);
            }
            j++;
        }
        if (mn < 1e9) {
            ans[i - 1] = mn;
        }
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