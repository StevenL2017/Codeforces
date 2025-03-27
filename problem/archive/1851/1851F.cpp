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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    vi idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&] (int i, int j) { return a[i] < a[j]; });

    int a1, a2, x, ans = -1;
    for (int i = 0; i < n - 1; i++) {
        int cx = ((1 << k) - 1) ^ (a[idx[i]] | a[idx[i + 1]]);
        int cur = (a[idx[i]] ^ cx) & (a[idx[i + 1]] ^ cx);
        if (cur > ans) {
            ans = cur;
            a1 = idx[i] + 1;
            a2 = idx[i + 1] + 1;
            x = cx;
        }
    }

    cout << a1 << " " << a2 << " " << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}