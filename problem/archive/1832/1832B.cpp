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
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    ll tot = 0;
    for (int i = 0; i < n; i++) {
        tot += a[i];
    }

    sort(a.begin(), a.end());
    ll suf = 0;
    for (int i = n - 1; i >= n - k; i--) {
        suf += a[i];
    }

    ll ans = suf, pre = 0;
    int i = 0, j = n - k;
    while (j < n) {
        pre += a[i] + a[i + 1];
        suf -= a[j];
        ans = min(ans, pre + suf);
        i += 2;
        j++;
    }

    cout << tot - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}