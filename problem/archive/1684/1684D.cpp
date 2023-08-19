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
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    ll ans = 0;
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        ans += a[i];
        b[i] = {-a[i] + n - 1 - i, i};
    }
    sort(b.begin(), b.end());

    vi c;
    for (int i = 0; i < k; i++) {
        c.push_back(b[i].second);
    }
    sort(c.begin(), c.end());

    for (int i = ssz(c) - 1; i >= 0; i--) {
        ans += -a[c[i]] + n - 1 - c[i] - (ssz(c) - 1 - i);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}