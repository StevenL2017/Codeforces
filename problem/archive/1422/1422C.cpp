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

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int ans = 0, suf = 0, p10 = 1, n = ssz(s);
    vi a10(n);
    for (int i = n - 1; i > 0; i--) {
        suf += (s[i] - '0') * 1ll * p10 % MOD;
        suf %= MOD;
        ans += i * 1ll * suf % MOD;
        ans %= MOD;
        a10[i - 1] = (a10[i] + p10) % MOD;
        p10 = p10 * 1ll * 10 % MOD;
    }
    int pre = 0;
    for (int i = 0; i < n - 1; i++) {
        pre = (pre * 1ll * 10 + (s[i] - '0')) % MOD;
        ans += pre * 1ll * a10[i] % MOD;
        ans %= MOD;
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