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
    int n, r, avg;
    cin >> n >> r >> avg;
    vector<pair<int, int>> a(n);
    ll tot = n * 1ll * avg;
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
        tot -= a[i].second;
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    int i = 0;
    while (tot > 0 && i < n) {
        ll cur = min(tot, 1ll * r - a[i].second);
        ans += cur * a[i].first;
        tot -= cur;
        if (tot) {
            i++;
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