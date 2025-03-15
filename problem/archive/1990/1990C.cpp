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

ll calc(vi& a) {
    ll ans = 0;
    int n = ssz(a), mx = 0;
    vi cnt(n + 1);
    for (int i = 0; i < n; i++) {
        ans += a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] >= 2) {
            mx = max(mx, a[i]);
        }
        a[i] = mx;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(a);

    ll ans = calc(a);
    ans += calc(a);
    for (int i = 0; i < n; i++) {
        ans += a[i] * 1ll * (n - i);
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