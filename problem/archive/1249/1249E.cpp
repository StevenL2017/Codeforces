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
    int n, c;
    cin >> n >> c;
    vi a(n - 1), b(n - 1);
    in(a); in(b);

    vi ans(n), f(2);
    f[1] = 1e9;
    for (int i = 0; i < n - 1; i++) {
        vi g(2);
        g[0] = min(f[0], f[1]) + a[i];
        g[1] = min(f[0] + c + b[i], f[1] + b[i]);
        ans[i + 1] = min(g[0], g[1]);
        f = g;
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}