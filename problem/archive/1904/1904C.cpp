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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    in(a);
    
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    sort(begin(a), end(a));

    ll ans = a[0];
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, a[i + 1] - a[i]);
    }

    if (k == 1) {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto d = a[j] - a[i];
            int idx = lower_bound(begin(a), end(a), d) - begin(a);
            if (idx > 0) {
                ans = min(ans, d - a[idx - 1]);
            }
            if (idx < n) {
                ans = min(ans, a[idx] - d);
            }
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