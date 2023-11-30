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
    int n; cin >> n;
    vi a(n); in(a);

    vi b = a;
    sort(b.begin(), b.end());

    vector<ll> pa(n + 1), pb(n + 1);
    for (int i = 0; i < n; i++) {
        pa[i + 1] = pa[i] + a[i];
        pb[i + 1] = pb[i] + b[i];
    }

    int m; cin >> m;
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        cout << (op == 1 ? pa[r] - pa[l - 1] : pb[r] - pb[l - 1]) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}