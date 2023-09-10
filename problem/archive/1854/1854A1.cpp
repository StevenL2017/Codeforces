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

    int mx = -21, mxi = -1;
    int mn = 21, mni = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) {
            mx = a[i];
            mxi = i;
        }
        if (a[i] < mn) {
            mn = a[i];
            mni = i;
        }
    }

    if (mx == 0 && mn == 0) {
        cout << 0 << endl;
        return;
    }

    vector<pair<int, int>> ans;
    if (mx > 0) {
        for (int i = 0; i < 9; i++) {
            ans.emplace_back(mxi + 1, mxi + 1);
        }
        ans.emplace_back(n, mxi + 1);
        for (int i = 0; i < n; i++) {
            ans.emplace_back(n, n);
            ans.emplace_back(i + 1, n);
        }
    } else {
        for (int i = 0; i < 9; i++) {
            ans.emplace_back(mni + 1, mni + 1);
        }
        ans.emplace_back(1, mni + 1);
        for (int i = n - 1; i >= 0; i--) {
            ans.emplace_back(1, 1);
            ans.emplace_back(i + 1, 1);
        }
    }

    cout << ssz(ans) << endl;
    for (auto [i, j]: ans) {
        cout << i << " " << j << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}