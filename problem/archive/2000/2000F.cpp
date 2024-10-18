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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector<vi> f(n + 1, vi(k + 1, 1e9));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (f[i][j] == 1e9) continue;
            int x = a[i].first, y = a[i].second, tot = 0;
            for (int c = 0; c <= k - j; c++) {
                f[i + 1][j + c] = min(f[i + 1][j + c], f[i][j] + tot);
                if (x == 0 && y == 0) break;
                if (x < y) {
                    tot += x;
                    y--;
                } else {
                    tot += y;
                    x--;
                }
            }
        }
    }
    cout << (f[n][k] == 1e9 ? -1 : f[n][k]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}