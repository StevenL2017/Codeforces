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
    int n, m;
    cin >> n >> m;
    vi a(n);
    in(a);

    vi dec(n);
    for (int i = 0, j = 0; i < n;) {
        dec[j] = i;
        while (j + 1 < n && a[j + 1] <= a[j]) {
            j++;
            dec[j] = i;
        }
        j++;
        i = j;
    }

    vi inc(n);
    for (int i = n - 1, j = n - 1; i >= 0;) {
        inc[j] = i;
        while (j - 1 >= 0 && a[j - 1] <= a[j]) {
            j--;
            inc[j] = i;
        }
        j--;
        i = j;
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << (inc[l] >= dec[r] ? "Yes" : "No") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}