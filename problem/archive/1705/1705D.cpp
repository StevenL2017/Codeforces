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
    string s, t;
    cin >> s >> t;

    if (s[0] != t[0] || s[n - 1] != t[n - 1]) {
        cout << -1 << endl;
        return;
    }

    vi ps, pt;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            ps.push_back(i);
        }
        if (t[i] != t[i + 1]) {
            pt.push_back(i);
        }
    }

    if (ssz(ps) != ssz(pt)) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;
    for (int i = 0; i < ssz(ps); i++) {
        ans += abs(ps[i] - pt[i]);
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