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
    int n, x, y;
    cin >> n >> x >> y;

    vector<ll> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = i * 1ll * x;
    }
    for (int i = 1; i <= n; i++) {
        if (2 * i <= n) {
            f[2 * i] = min(f[2 * i], f[i] + y);
        }
        if (2 * i + 1 <= n) {
            f[2 * i + 1] = min(f[2 * i + 1], f[i] + y + x);
        }
        if (2 * i - 1 <= n) {
            f[2 * i - 1] = min(f[2 * i - 1], f[i] + y + x);
        }
    }
    cout << f[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}