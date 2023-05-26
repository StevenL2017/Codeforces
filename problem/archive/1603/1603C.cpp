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

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

void solve() {
    int n; cin >> n;
    vi a(n); in(a);

    int mx = *max_element(a.begin(), a.end());

    int ans = 0;
    vector<vi> f(2, vi(mx + 1, 0)), s(2);
    for (int i = n - 1; i >= 0; i--) {
        int b = i & 1;
        f[b][a[i]] = 1;
        s[b].push_back(a[i]);
        for (auto x : s[b ^ 1]) {
            int k = (a[i] + x - 1) / x;
            int y = a[i] / k;
            f[b][y] += f[b ^ 1][x];
            if (y != s[b].back()) s[b].push_back(y);
            ans = add(ans, mul(mul(i + 1, f[b ^ 1][x]), k - 1));
        }
        for (auto x : s[b ^ 1]) {
            f[b ^ 1][x] = 0;
        }
        s[b ^ 1].clear();
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