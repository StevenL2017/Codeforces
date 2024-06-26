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

    vi left(n), right(n);
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1];
        if (i == n - 1 || a[i] - a[i - 1] < a[i + 1] - a[i]) {
            left[i]++;
        } else {
            left[i] += a[i] - a[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1];
        if (i == 0 || a[i + 1] - a[i] < a[i] - a[i - 1]) {
            right[i]++;
        } else {
            right[i] += a[i + 1] - a[i];
        }
    }

    int m; cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        if (l < r) {
            cout << right[l] - right[r] << endl;
        } else {
            cout << left[l] - left[r] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}