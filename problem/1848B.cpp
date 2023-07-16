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
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    vector<vi> c(k + 1);
    for (int i = 0; i < n; i++) {
        c[a[i]].push_back(i);
    }

    int ans = n;
    for (int x = 1; x <= k; x++) {
        if (c[x].empty()) continue;
        sort(c[x].begin(), c[x].end());
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i <= ssz(c[x]); i++) {
            int d = 0;
            if (i == 0) d = c[x][i];
            else if (i == ssz(c[x])) d = n - 1 - c[x][i - 1];
            else d = c[x][i] - c[x][i - 1] - 1;
            if (d > mx1) {
                mx2 = mx1;
                mx1 = d;
            } else if (d > mx2) {
                mx2 = d;
            }
        }
        ans = min(ans, max(mx1 / 2, mx2));
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