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
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vi f(n + 1, 0);
    if (a <= n) f[a] = 1;
    if (b <= n) f[b] = 1;
    if (c <= n) f[c] = 1;
    for (int i = 1; i <= n; i++) {
        if (!f[i]) continue;
        if (i + a <= n) f[i + a] = max(f[i + a], f[i] + 1);
        if (i + b <= n) f[i + b] = max(f[i + b], f[i] + 1);
        if (i + c <= n) f[i + c] = max(f[i + c], f[i] + 1);
    }

    cout << f[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}