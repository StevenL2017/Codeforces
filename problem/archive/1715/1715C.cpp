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
    int n, m;
    cin >> n >> m;
    vi a(n);
    in(a);

    ll ans = 1, pre = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            pre++;
        } else {
            pre += i + 1;
        }
        ans += pre;
    }

    while (m--) {
        int idx, x;
        cin >> idx >> x;
        idx--;

        if (idx > 0) {
            if (a[idx - 1] == a[idx] && a[idx - 1] != x) {
                ans += idx * 1ll * (n - idx);
            } else if (a[idx - 1] != a[idx] && a[idx - 1] == x) {
                ans -= idx * 1ll * (n - idx);
            }
        }
        if (idx < n - 1) {
            if (a[idx] == a[idx + 1] && x != a[idx + 1]) {
                ans += (idx + 1) * 1ll * (n - idx - 1);
            } else if (a[idx] != a[idx + 1] && x == a[idx + 1]) {
                ans -= (idx + 1) * 1ll * (n - idx - 1);
            }
        }
        a[idx] = x;

        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}