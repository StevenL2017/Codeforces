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
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }

    ll ans = 0;
    int tot = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (i == tot) {
            ans += p;
            tot++;
        }
        if (a[i].first < p) {
            int cnt = min(n - tot, a[i].second);
            ans += a[i].first * 1ll * cnt;
            tot += cnt;
        }
        if (tot == n) break;
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