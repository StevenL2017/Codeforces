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
    vi a(6); in(a);
    int n; cin >> n;
    vi b(n); in(b);

    vector<pair<int, int>> c;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < n; j++) {
            c.emplace_back(b[j] - a[i], j);
        }
    }
    sort(c.begin(), c.end());

    int ans = INT_MAX, cnt = 0;
    vi vis(n, 0);
    for (int i = 0, j = 0; i < ssz(c); i++) {
        if (vis[c[i].second] == 0) cnt++;
        vis[c[i].second]++;
        while (j <= i && cnt == n) {
            ans = min(ans, c[i].first - c[j].first);
            vis[c[j].second]--;
            if (vis[c[j].second] == 0) cnt--;
            j++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}