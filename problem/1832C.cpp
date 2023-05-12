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
    int n; cin >> n;
    vi a(n); in(a);

    vi b;
    b.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] != b.back()) {
            b.push_back(a[i]);
        }
    }

    if (ssz(b) == 1) {
        cout << 1 << endl;
        return;
    }

    int ans = 2;
    ll pre = b[1] - b[0];
    for (int i = 2; i < ssz(b); i++) {
        ll cur = b[i] - b[i - 1];
        if (pre * cur < 0) {
            ans++;
        }
        pre = cur;
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