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
    vector<vi> a(n, vi(3));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    sort(a.begin(), a.end(), [&] (vi& x, vi& y) { return x[1] > y[1] || x[1] == y[1] && x[0] > y[0]; });

    ll ans = 0;
    vector<vector<ll>> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.back()[0] >= a[i][1]) {
            st.pop_back();
        }
        ll h = (st.empty() ? a[i][2] : st.back()[2] + a[i][2]);
        st.push_back({a[i][0], a[i][1], h});
        ans = max(ans, h);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}