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
    string a, b;
    cin >> a >> b;

    int n = ssz(a), m = ssz(b);
    vi pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (a[i] - '0');
    }
    int c1 = 0;
    for (auto c: b) {
        c1 += c - '0';
    }

    int ans = 0;
    for (int i = m; i <= n; i++) {
        if (((pre[i] - pre[i - m]) & 1) == (c1 & 1)) {
            ans++;
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