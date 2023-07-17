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

ll calc(ll s, ll k) {
    ll ans = s * k;
    ll x = (5 * k - s) / 40;
    x = min(x, k / 4);
    if (x > 0) ans = max(ans, (s + 20 * x) * (k - 4 * x));
    x = min(x + 1, k / 4);
    if (x > 0) ans = max(ans, (s + 20 * x) * (k - 4 * x));
    return ans;
}

void solve() {
    ll s, k; cin >> s >> k;

    int last = s % 10;
    if (last == 0) {
        cout << s * k << endl;
        return;
    }
    if (last == 5) {
        cout << max(s * k, (s + 5) * (k - 1)) << endl;
        return;
    }

    ll ans = s * k;
    for (int i = 0; i < 10; i++) {
        int last = s % 10;
        s += last;
        k--;
        ans = max(ans, calc(s, k));
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