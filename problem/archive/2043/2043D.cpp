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
    ll l, r, g;
    cin >> l >> r >> g;

    l += (l % g == 0 ? 0 : g - l % g);
    r -= r % g;

    for (int i = 0; i <= (r - l) / g; i++) {
        for (int j = 0; j <= i; j++) {
            if (gcd(l + j * g, r - (i - j) * g) == g) {
                cout << l + j * g << " " << r - (i - j) * g << endl;
                return;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}