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
    int a, b, c; ll k;
    cin >> a >> b >> c >> k;

    int x_mn = pow(10, a - 1), x_mx = pow(10, a) - 1;
    int y_mn = pow(10, b - 1), y_mx = pow(10, b) - 1;
    int z_mn = pow(10, c - 1), z_mx = pow(10, c) - 1;

    for (int x = x_mn; x <= x_mx; x++) {
        int l = max(x + y_mn, z_mn), r = min(x + y_mx, z_mx);
        if (l > r) continue;
        int cnt = r - l + 1;
        if (k > cnt) {
            k -= cnt;
        } else {
            int y = l - x + k - 1;
            cout << x << " + " << y << " = " << x + y << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}