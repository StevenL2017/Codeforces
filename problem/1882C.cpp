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
    int n; cin >> n;
    vi a(n); in(a);

    ll ans = 0, even = 0;
    int last = n;
    for (int i = n; i > 0; i--) {
        if (i % 2 == 0) {
            even = max(even, even + a[i - 1]);
        } else {
            if (a[i - 1] >= 0) {
                ans += a[i - 1];
                ans += even;
                even = 0;
                last = i - 1;
            }
        }
    }

    ll extra = 0;
    for (int i = 1; i <= last; i++) {
        if (i & 1) {
            extra = max(extra, even + a[i - 1]);
        } else {
            if (a[i - 1] >= 0) {
                even -= a[i - 1];
            }
            extra = max(extra, even);
        }
    }

    cout << ans + extra << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}