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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 3;

int pow2[MAXN];

int add(int x, int y) {
    x += y;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (x * 1ll * y) % MOD;
}

int fastexp(int b, int exp) {
    if (exp == 0) return 1;
    int temp = fastexp(b, exp / 2);
    temp = mul(temp, temp);
    if (exp % 2 == 1) temp = mul(temp, b);
    return temp;
}

void precompute(int n) {
    for (int i = 0; i <= n; i++)
        pow2[i] = fastexp(2, i);
}

void solve() {
    int n; cin >> n;
    vector<vi> e(n);
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int ans = 0;
    function<int(int, int, int)> dfs = [&] (int u, int p, int d) -> int {
        int cur = d;
        for (auto& v: e[u]) {
            if (v == p) continue;
            cur = max(cur, dfs(v, u, d + 1));
        }
        ans = add(ans, cur - d + 1);
        return cur;
    };
    dfs(0, -1, 0);

    cout << mul(ans, pow2[n - 1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute(MAXN - 1);
    int t = 1;
    cin >> t;
    while (t--) solve();
}