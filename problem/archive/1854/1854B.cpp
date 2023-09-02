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

const int N = 2e5 + 3;

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    ll ans = 0;
    bitset<N> f{};
    f[1] = 1;
    for (int i = 0; i < n; i++) {
        f |= f << a[i];
        if (f[i + 1]) {
            f[i + 1] = 0;
            ans = max(ans, pre[i + 1] - i);
        }
    }
    for (int i = n; i <= 2 * n; i++) {
        if (f[i]) {
            ans = max(ans, pre[n] - i + 1);
        }
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