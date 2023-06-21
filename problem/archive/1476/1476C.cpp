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
    vi c(n); in(c);
    vi a(n); in(a);
    vi b(n); in(b);

    ll ans = 0, pre = 0;
    for (int i = 1; i < n; i++) {
        if (i == 1 || a[i] == b[i]) {
            pre = c[i] + 1ll + abs(a[i] - b[i]);
        } else {
            pre = max(pre + c[i] + 1ll - abs(a[i] - b[i]), c[i] + 1ll + abs(a[i] - b[i]));
        }
        ans = max(ans, pre);
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