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
    vi a(n), b(m);
    in(a); in(b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    vector<ll> pre_a(1, 0), pre_b(1, 0);
    for (int i = 0; i < n; i++) {
        pre_a.push_back(pre_a.back() + a[i]);
    }
    for (int i = 0; i < m; i++) {
        pre_b.push_back(pre_b.back() + b[i]);
    }

    ll ans = abs(pre_b[n] - pre_a[n]);
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans, abs(pre_b[i] - pre_a[i]) + abs(pre_b[m] - pre_b[m - (n - i)] - (pre_a[n] - pre_a[i])));
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