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

const int MOD = 998244353;

void solve() {
    int n, a1, x, y, m, k;
    cin >> n >> a1 >> x >> y >> m >> k;

    vector<int> a(n, a1);
    for (int i = 1; i < n; i++) {
        a[i] = (a[i - 1] * 1ll * x % m + y) % m;
    }
    for (int j = 0; j <= k; j++) {
        for (int i = 1; i < n; i++) {
            a[i] = (a[i - 1] + a[i]) % MOD;
        }
    }
    
    ll ans = 0;
    for (int i = k - 1; i < n; i++) {
        ans ^= a[i - (k - 1)] * 1ll * (i + 1);
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