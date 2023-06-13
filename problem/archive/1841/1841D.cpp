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
    vi l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return r[i] < r[j]; });

    int ans = 0, cut = -1, pre = -1;
    for (auto i : idx) {
        if (l[i] <= cut) {
            continue;
        }
        if (l[i] <= pre) {
            ans++;
            cut = r[i];
        } else {
            pre = r[i];
        }
    }

    cout << n - 2 * ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}