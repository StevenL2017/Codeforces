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

const int N = 24;
const int M = 1 << N;
int d[N + 1][N + 1];
int f[M];
int p[M][3];

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    a[n].first = x;
    a[n].second = y;

    auto calc = [&] (int i, int j) -> int {
        auto [x1, y1] = a[i];
        auto [x2, y2] = a[j];
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    };

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = calc(i, j);
        }
    }

    map<int, int> mp;
    for (int i = 0; i <= n; i++) {
        mp[1 << i] = i;
    }

    int m = 1 << n;
    for (int i = 1; i < m; i++) {
        f[i] = 2e9;
    }
    for (int mask = 0; mask < m; mask++) {
        int x = mask ^ (m - 1);
        int i = mp[x & -x];
        for (int y = x; y; y -= y & -y) {
            int j = mp[y & -y];
            int nmask = mask | (1 << i) | (1 << j);
            int cost = f[mask] + d[n][i] + d[i][j] + d[j][n];
            if (cost < f[nmask]) {
                f[nmask] = cost;
                p[nmask][0] = i;
                p[nmask][1] = j;
                p[nmask][2] = mask;
            }
        }
    }

    vi ans;
    int cur = m - 1;
    while (cur) {
        auto i = p[cur][0];
        auto j = p[cur][1];
        auto pre = p[cur][2];
        ans.push_back(0);
        ans.push_back(j + 1);
        if (i != j) {
            ans.push_back(i + 1);
        }
        cur = pre;
    }
    ans.push_back(0);
    reverse(begin(ans), end(ans));

    cout << f[m - 1] << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}