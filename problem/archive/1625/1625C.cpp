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
    int n, l, k;
    cin >> n >> l >> k;
    vi d(n); in(d);
    vi a(n); in(a);

    d.push_back(l);
    vector<vi> f(n + 1, vi(k + 1, 2e9));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int c = 0; c <= k; c++) {
                if (c + i - j - 1 > k) continue;
                if (f[j][c] == 2e9) continue;
                f[i][c + i - j - 1] = min(f[i][c + i - j - 1], f[j][c] + (d[i] - d[j]) * a[j]);
            }
        }
    }

    cout << *min_element(f[n].begin(), f[n].end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}