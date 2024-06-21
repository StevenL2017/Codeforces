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

int max_subarray_sum(vi& a) {
    int ans = 0, mx = 0;
    for (auto x : a) {
        mx = max(mx + x, x);
        ans = max(ans, mx);
    }
    return ans;
}

void solve() {
    int n, c;
    cin >> n >> c;
    vi a(n);
    in(a);

    vector<ll> pre(n + 1);
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (a[i] == c);
        mx = max(mx, a[i]);
    }

    vector<vi> seg(mx + 1);
    vi last(mx + 1, -1);
    for (int i = 0; i < n; i++) {
        seg[a[i]].push_back(pre[last[a[i]] + 1] - pre[i]);
        seg[a[i]].push_back(1);
        last[a[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= mx; i++) {
        if (i == c || seg[i].empty()) continue;
        ans = max(ans, max_subarray_sum(seg[i]));
    }

    cout << pre[n] + ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}