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
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    map<string, int> mp;
    int c = 0;
    for (int i = 0; i < n; i++) {
        string g, w;
        cin >> g >> w;
        if (mp.find(g) == mp.end()) {
            mp[g] = c++;
        }
        if (mp.find(w) == mp.end()) {
            mp[w] = c++;
        }
        a.emplace_back(mp[g], mp[w]);
    }

    vector<vi> f(1 << n, vi(n));
    for (int i = 0; i < n; i++) {
        f[1 << i][i] = 1;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!f[mask][i]) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (mask >> j & 1) {
                    continue;
                }
                if (a[i].first == a[j].first || a[i].second == a[j].second) {
                    f[mask | (1 << j)][j] = max(f[mask | (1 << j)][j], f[mask][i] + 1);
                }
            }
        }
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (f[mask][i]) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
    }
    cout << n - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}