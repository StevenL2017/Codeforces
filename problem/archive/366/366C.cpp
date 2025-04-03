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
    vi a(n), b(n);
    in(a);
    in(b);

    vi c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i] * k;
    }

    map<int, int> f;
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        map<int, int> g = f;
        for (auto [k, v]: f) {
            g[k + c[i]] = max(g[k + c[i]], v + a[i]);
        }
        f = g;
    }
    cout << (f[0] ? f[0] : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}