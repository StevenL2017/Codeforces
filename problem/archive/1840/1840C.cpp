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
    int n, k, q;
    cin >> n >> k >> q;
    vi a(n); in(a);

    vi b(1, -1);
    for (int i = 0; i < n; i++) {
        if (a[i] > q) {
            b.push_back(i);
        }
    }
    b.push_back(n);

    ll ans = 0;
    for (int i = 0; i < ssz(b) - 1; i++) {
        int l = b[i + 1] - b[i] - 1;
        if (l >= k) {
            ans += (1 + l - k + 1) * 1ll * (1 + l - k) / 2;
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