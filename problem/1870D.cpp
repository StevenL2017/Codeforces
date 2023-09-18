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
    int n; cin >> n;
    vi c(n); in(c);
    int k; cin >> k;

    for (int i = n - 2; i >= 0; i--) {
        c[i] = min(c[i], c[i + 1]);
    }

    vi ans(n);
    int cur = k;
    for (int i = 0; i < n; i++) {
        int v = c[i] - (i ? c[i - 1] : 0);
        if (v) {
            cur = min(cur, k / v);
        }
        k -= cur * v;
        ans[i] = cur;
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