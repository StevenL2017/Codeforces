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

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

void solve() {
    int r, g;
    cin >> r >> g;

    int h = 0;
    while (h * (h + 1) / 2 <= r + g) {
        h++;
    }
    h--;

    vi f(r + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = r; j >= i; j--) {
            f[j] = add(f[j], f[j - i]);
        }
    }

    int ans = 0, tot = h * (h + 1) / 2;
    for (int i = 0; i <= r; i++) {
        if (tot - i >= 0 && tot - i <= g) {
            ans = add(ans, f[i]);
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