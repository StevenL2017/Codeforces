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

    vi mn(n + 1, n), mx(n + 1, -1);
    for (int i = 0; i < n; i++) {
        mn[a[i]] = min(mn[a[i]], i);
        mx[a[i]] = max(mx[a[i]], i);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int ans = n, m = ssz(a);
    vi f(m, 1);
    for (int i = m - 1; i >= 0; i--) {
        if (i == m - 1 || mx[a[i]] > mn[a[i + 1]]) f[i] = 1;
        else f[i] = f[i + 1] + 1;
        ans = min(ans, m - f[i]);
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