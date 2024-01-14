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
    int mn = 1, mx = 1e9;
    vi d;
    for (int i = 0; i < n; i++) {
        int a, x;
        cin >> a >> x;
        if (a == 1) {
            mn = max(mn, x);
        } else if (a == 2) {
            mx = min(mx, x);
        } else {
            d.push_back(x);
        }
    }

    int ans = max(0, mx - mn + 1);
    for (auto x: d) {
        if (x >= mn && x <= mx) ans--;
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