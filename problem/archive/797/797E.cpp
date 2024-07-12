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

    int s = (int)(sqrt(n)) + 1;
    vector<vi> f(n, vi(s, 1));
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j < s; j++) {
            if (i + 1 + a[i] + j <= n) {
                f[i][j] = f[i + 1 + a[i] + j - 1][j] + 1;
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int p, k;
        cin >> p >> k;
        if (k < s) {
            cout << f[p - 1][k] << endl;
        } else {
            int ans = 0;
            while (p <= n) {
                p += a[p - 1] + k;
                ans++;
            }
            cout << ans << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}