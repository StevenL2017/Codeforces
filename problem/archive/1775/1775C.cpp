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
    ll n, x;
    cin >> n >> x;

    if ((n & x) != x) {
        cout << -1 << endl;
        return;
    }

    int d = -1;
    for (int i = 62; i >= 0; i--) {
        if ((n >> i & 1ll)) {
            if (d >= 0 && (x >> i & 1ll)) {
                cout << -1 << endl;
                return;
            }
            if (d == -1 && !(x >> i & 1ll)) {
                d = i;
                if (n >> (d + 1) & 1ll) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    if (d == -1) {
        cout << n << endl;
        return;
    }

    ll ans = 1ll << (d + 1);
    for (int i = d + 1; i < 63; i++) {
        if (n >> i & 1ll) {
            ans |= (x >> i & 1ll) << i;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}