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
    vi a(n);
    in(a);

    ll tot = 0;
    multiset<int> s;
    vector<ll> f(n + 1, 1e18);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        f[i + 1] = min(f[i + 1], f[i] + a[i]);
        tot += a[i];
        s.insert(a[i]);
        if (i >= c) {
            tot -= a[i - c];
            s.extract(a[i - c]);
        }
        if (i >= c - 1) {
            f[i + 1] = min(f[i + 1], f[i + 1 - c] + tot - *s.begin());
        }
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