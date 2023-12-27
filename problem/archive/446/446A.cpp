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

    vi suf(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) suf[i] = suf[i + 1] + 1;
    }

    int ans = min(n, *max_element(suf.begin(), suf.end()) + 1), pre = 1;
    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] > a[i - 1] + 1) ans = max(ans, pre + suf[i + 1] + 1);
        if (a[i] > a[i - 1]) pre++;
        else pre = 1;
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