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

int sub(int x, int y) {
    return add(x, -y);
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(a);

    int ans = 0;
    for (int i = 0; i < 30; i++) {
        int cur = 0, k = 0;
        vi cnt(2), pre(2);
        cnt[0] = 1;
        for (int j = 0; j < n; j++) {
            k ^= a[j] >> i & 1;
            cur = add(cur, sub(mul(cnt[k ^ 1], j + 1), pre[k ^ 1]));
            cnt[k]++;
            pre[k] = add(pre[k], j + 1);
        }
        ans = add(ans, mul(1 << i, cur));
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