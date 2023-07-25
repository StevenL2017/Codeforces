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
    int n, k, q;
    cin >> n >> k >> q;
    vi d(200002, 0);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        d[l]++;
        d[r + 1]--;
    }

    for (int i = 1; i < 200002; i++) {
        d[i] += d[i - 1];
    }
    for (int i = 0; i < 200002; i++) {
        d[i] = (int)(d[i] >= k);
    }
    for (int i = 1; i < 200002; i++) {
        d[i] += d[i - 1];
    }

    while (q--) {
        int l, r; cin >> l >> r;
        cout << d[r] - d[l - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}