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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m), c(k);
    in(a);
    in(b);
    in(c);

    int mx = 0, mx2 = 0, idx = 0;
    for (int i = 1; i < n; i++) {
        int d = a[i] - a[i - 1];
        if (d > mx) {
            mx2 = mx;
            mx = d;
            idx = i - 1;
        } else if (d > mx2) {
            mx2 = d;
        }
    }

    int ans = 2e9, target = a[idx] + (a[idx + 1] - a[idx]) / 2;
    sort(begin(b), end(b));
    sort(begin(c), end(c));
    for (int i = 0, j = k - 1; i < m; i++) {
        while (j >= 0 && b[i] + c[j] > target) {
            auto x = b[i] + c[j];
            if (x < a[idx + 1]) {
                ans = min(ans, max({mx2, a[idx + 1] - x, x - a[idx]}));
            }
            j--;
        }
        if (j < 0) {
            break;
        }
        auto x = b[i] + c[j];
        if (x > a[idx]) {
            ans = min(ans, max({mx2, a[idx + 1] - x, x - a[idx]}));
        }
    }

    cout << (ans < 2e9 ? ans : mx) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}