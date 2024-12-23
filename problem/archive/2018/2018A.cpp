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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    in(a);

    ll s = 0, mx = 0;
    for (auto x: a) {
        s += x;
        mx = max(mx, x);
    }

    if (mx * n <= s + k) {
        cout << n << endl;
        return;
    }

    for (int x = n; x >= 1; x--) {
        if (s <= x * mx && x * mx <= s + k) {
            cout << x << endl;
            return;
        }
        if (s > x * mx && k >= (x - s % x) % x) {
            cout << x << endl;
            return;
        }
    }

    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}