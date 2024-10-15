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
    int n, k, d;
    cin >> n >> k >> d;
    vi a(n), v(k);
    in(a);
    in(v);

    ll ans = 0;
    for (int i = 0; i < min(d, 2 * n + 1); i++) {
        ll cur = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == j + 1) cur++;
            if (j < v[i % k]) a[j]++;
        }
        cur += (d - i - 1) / 2;
        ans = max(ans, cur);
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