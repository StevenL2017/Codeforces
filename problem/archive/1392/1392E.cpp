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

    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i & 1) a[i][j] = 1ll << (i + j);
        }
    }

    for (int i = 0; i < n; i++) {
        out(a[i]);
        cout.flush();
    }

    int q; cin >> q;

    while (q--) {
        ll k; cin >> k;

        int r = 0, c = 0;
        while (r < n - 1 || c < n - 1) {
            cout << r + 1 << " " << c + 1 << endl;
            cout.flush();
            if (r == n - 1) {
                c++;
            } else if (c == n - 1) {
                r++;
            } else {
                if (r % 2 == 0) {
                    if (k >> (r + 1 + c) & 1) r++;
                    else c++;
                } else {
                    if (k >> (r + c + 1) & 1) c++;
                    else r++;
                }
            }
        }
        cout << r + 1 << " " << c + 1 << endl;
        cout.flush();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}