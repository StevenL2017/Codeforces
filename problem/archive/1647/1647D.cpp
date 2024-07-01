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
    int x, d;
    cin >> x >> d;

    int cnt = 0;
    while (x % d == 0) {
        cnt++;
        x /= d;
    }

    int y = 1, c1 = 0;
    while (y * y <= x) {
        if (x % y == 0) {
            if (y % d != 0 && (x / y) % d != 0) {
                c1++;
            }
        }
        y++;
    }

    int z = 2, c2 = 0;
    x *= d;
    while (z * z <= x) {
        if (x % z == 0) {
            if (z % d != 0 && (x / z) % d != 0) {
                c2++;
            }
        }
        z++;
    }
    x /= d;

    if (cnt > 1 && c1 >= 2 || cnt > 2 && c2 >= 1 || cnt > 3 && x * x == d) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}