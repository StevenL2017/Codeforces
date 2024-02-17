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

ll f[31][31][51];

ll calc(int x, int y, int z) {
    if (f[x][y][z] || x * y == z || z == 0) {
        return f[x][y][z];
    }
    ll ans = 2e9;
    for (int i = 1; i <= x - i; i++) {
        for (int j = 0; j <= z; j++) {
            ans = min(ans, y * y + calc(i, y, j) + calc(x - i, y, z - j));
        }
    }
    for (int i = 1; i <= y - i; i++) {
        for (int j = 0; j <= z; j++) {
            ans = min(ans, x * x + calc(x, i, j) + calc(x, y - i, z - j));
        }
    }
    return f[x][y][z] = ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    cout << calc(n, m, k) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}