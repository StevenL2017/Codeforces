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
    int n, m; cin >> n >> m;
    vi a(n), b(m);
    in(a); in(b);

    ll tot_a = 0, tot_b = 0;
    for (int i = 0; i < n; i++) {
        tot_a += a[i];
    }
    for (int i = 0; i < m; i++) {
        tot_b += b[i];
    }

    if (tot_a > tot_b) {
        cout << "Tsondu\n";
    } else if (tot_a < tot_b) {
        cout << "Tenzing\n";
    } else {
        cout << "Draw\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}