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
    vector<pair<int, int>> a(n + 1);
    a[0] = {-1e9, 1e9};
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(begin(a), end(a));

    int ans = n - 1;
    vi f(n + 1, 1);
    f[0] = 0;
    for (int i = 2; i <= n; i++) {
        int l = a[i].first - a[i].second;
        int j = lower_bound(begin(a), end(a), make_pair(l, 0)) - begin(a) - 1;
        f[i] = f[j] + 1;
        ans = min(ans, n - f[i]);
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