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
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    vi a(n);
    in(a);

    int tot = 0;
    for (auto x: a) tot += x;

    vi f(tot + 1);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = tot; j - a[i] >= 0; j--) {
            f[j] |= f[j - a[i]];
        }
    }

    int ans = 1e9;
    for (int i = 0; i <= tot; i++) {
        if (!f[i]) continue;
        ans = min(ans, max((i + x - 1) / x, (tot - i + y - 1) / y));
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