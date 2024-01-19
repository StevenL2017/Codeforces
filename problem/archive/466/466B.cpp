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
    ll n, a, b;
    cin >> n >> a >> b;

    if (6 * n <= a * b) {
        cout << a * b << endl;
        cout << a << " " << b << endl;
        return;
    }

    bool rev = false;
    if (a > b) {
        swap(a, b);
        rev = true;
    }

    ll ans = LLONG_MAX, new_a = a, new_b = b;
    for (ll x = a; x * x <= 6 * n; x++) {
        ll y = 6 * n / x;
        if (x * y < 6 * n) y++;
        if (y < b) continue;
        if (x * y < ans) {
            ans = x * y;
            new_a = x;
            new_b = y;
        }
    }

    if (rev) {
        swap(new_a, new_b);
    }

    cout << ans << endl;
    cout << new_a << " " << new_b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}