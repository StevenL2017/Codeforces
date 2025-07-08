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

    vi pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = max(pre[i], a[i]);
    }

    vi suf(n + 1, 1e9);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = min(suf[i + 1], a[i]);
    }

    vi ans(n);
    ans[n - 1] = pre[n];
    for (int i = n - 2; i >= 0; i--) {
        if (pre[i + 1] > suf[i + 1]) {
            ans[i] = ans[i + 1];
        } else {
            ans[i] = pre[i + 1];
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