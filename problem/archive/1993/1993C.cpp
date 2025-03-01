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
    vi a(n);
    in(a);

    vi cnt(2 * k);
    int mx = -1;
    for (auto x: a) {
        cnt[x % (2 * k)]++;
        mx = max(mx, x);
    }

    int tot = 0;
    for (int i = 0; i < k - 1; i++) {
        tot += cnt[i];
    }

    int ans = INT_MAX;
    for (int l = 0, r = k - 1; l < 2 * k; l++, r++) {
        r %= 2 * k;
        tot += cnt[r];
        if (tot == n) {
            ans = min(ans, mx + ((r - mx) % (2 * k) + 2 * k) % (2 * k));
        }
        tot -= cnt[l];
    }

    cout << (ans < INT_MAX ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}