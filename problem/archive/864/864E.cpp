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
    vi t(n), d(n), p(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> d[i] >> p[i];
        s += t[i];
    }

    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (int i, int j) { return d[i] < d[j]; });

    vi f(s + 1);
    vector<vi> v(s + 1);
    for (int k = 0; k < n; k++) {
        int i = idx[k];
        for (int j = d[i] - 1; j >= t[i]; j--) {
            int nxt = f[j - t[i]] + p[i];
            if (f[j] < nxt) {
                f[j] = nxt;
                v[j] = v[j - t[i]];
                v[j].push_back(i + 1);
            }
        }
    }

    int ans = 0, j = 0;
    for (int i = 0; i <= s; i++) {
        if (f[i] > ans) {
            ans = f[i];
            j = i;
        }
    }

    cout << ans << endl;
    cout << ssz(v[j]) << endl;
    out(v[j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}