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
    int n, c; cin >> n >> c;
    vi a(n); in(a);
    vi b(n - 1); in(b);

    ll ans = LLONG_MAX, pre = 0, day = 0;
    for (int i = 0; i < n; i++) {
        ans = min(ans, 1ll * (c - pre + a[i] - 1) / a[i] + day);
        if (i == n - 1) break;
        if (pre < b[i]) {
            ll d = 1ll * (b[i] - pre + a[i] - 1) / a[i];
            pre += d * a[i];
            day += d;
        }
        pre -= b[i];
        day++;
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