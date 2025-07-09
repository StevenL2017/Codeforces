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
    int n, m, k;
    cin >> n >> m >> k;

    bool even = k % 2 == 0;
    if (even) k >>= 1;

    if ((n * 1ll * m) % k) {
        cout << "NO" << endl;
        return;
    }

    int g = gcd(n, k);
    int a = n / g, kk = k / g;
    int b = m / kk;

    if (!even) {
        if (a < n) {
            a <<= 1;
        } else {
            b <<= 1;
        }
    }

    cout << "YES" << endl;
    cout << 0 << " " << 0 << endl;
    cout << a << " " << 0 << endl;
    cout << 0 << " " << b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}