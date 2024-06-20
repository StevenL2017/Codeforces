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

    ll s = 0;
    int first = n;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (a[i] == 0 && first == n) first = i;
    }

    int ans = 0, mx = 0;
    map<ll, int> cnt;
    for (int i = n - 1; i >= first; i--) {
        cnt[s]++;
        mx = max(mx, cnt[s]);
        if (a[i] == 0) {
            ans += mx;
            mx = 0;
            cnt.clear();
        }
        s -= a[i];
    }
    for (int i = first - 1; i >= 0; i--) {
        if (s == 0) ans++;
        s -= a[i];
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