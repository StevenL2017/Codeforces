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
    vi a(n); in(a);
    int q; cin >> q;
    vector<pair<int, int>> query(q);
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        query[i].first = t;
        query[i].second = i;
    }

    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    sort(query.begin(), query.end());

    vi ans(q, -1);
    int j = 1, ok = 0;
    for (auto [t, i] : query) {
        while (!ok && j <= n && t * 1ll * j >= pre[j]) {
            j++;
        }
        if (j <= n && t * 1ll * j < pre[j]) {
            continue;
        }
        ok = 1;
        while (j - 1 > 0 && t * 1ll * (j - 1) >= pre.back()) {
            j--;
        }
        ans[i] = j;
    }

    for (auto x : ans) cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}