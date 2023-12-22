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

    ll s = 0;
    vector<pair<ll, int>> pre;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (pre.empty() || s > pre.back().first) {
            pre.emplace_back(s, i);
        }
    }
    ll mx = pre.back().first;

    while (m--) {
        int x; cin >> x;

        if (s <= 0 && mx < x) {
            cout << -1 << " ";
            continue;
        }

        ll cnt = 0;
        if (mx < x) cnt = (x - mx + s - 1) / s;
        x -= cnt * s;
        auto idx = lower_bound(pre.begin(), pre.end(), make_pair(1ll * x, -1)) - pre.begin();
        cout << cnt * n + pre[idx].second << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}