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
    vi a(n);
    in(a);

    int g = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
        mx = max(mx, a[i]);
    }

    mx /= g;
    vi f(mx + 1, 1e9);
    for (int i = 0; i < n; i++) {
        a[i] /= g;
        f[a[i]] = 0;
    }

    for (int x = mx; x >= 0; x--) {
        if (f[x] >= 1e9) {
            continue;
        }
        for (int i = 0; i < n; i++) {
            int cur = gcd(x, a[i]);
            f[cur] = min(f[cur], f[x] + 1);
        }
    }

    int ans = max(0, f[1] - 1);
    for (int i = 0; i < n; i++) {
        if (a[i] > 1) {
            ans++;
        }
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