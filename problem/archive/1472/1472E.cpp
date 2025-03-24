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
    vi h(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
        if (h[i] > w[i]) {
            swap(h[i], w[i]);
        }
    }

    vi idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&] (int i, int j) { return h[i] < h[j]; });

    vi ans(n, -1);
    int mn = -1;
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && h[idx[j]] == h[idx[i]]) {
            j++;
        }
        for (int k = i; k < j; k++) {
            if (mn != -1 && w[mn] < w[idx[k]]) {
                ans[idx[k]] = mn + 1;
            }
        }
        for (int k = i; k < j; k++) {
            if (mn == -1 || w[mn] > w[idx[k]]) {
                mn = idx[k];
            }
        }
        i = j;
    }

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}