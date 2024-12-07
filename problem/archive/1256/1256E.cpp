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

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return a[i] < a[j]; });

    vector<ll> f(n + 1, 1e18);
    f[0] = 0;
    vi pre(n + 1, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 3; j < 6; j++) {
            if (i + j <= n && f[i + j] > f[i] + a[idx[i + j - 1]] - a[idx[i]]) {
                f[i + j] = f[i] + a[idx[i + j - 1]] - a[idx[i]];
                pre[i + j] = i;
            }
        }
    }

    int k = 1;
    vi ans(n);
    int cur = pre[n];
    for (int i = n; i > 0; i--) {
        if (i == cur) {
            cur = pre[i];
            k++;
        }
        ans[idx[i - 1]] = k;
    }

    cout << f[n] << " " << k << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}