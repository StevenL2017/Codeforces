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

    vector<vi> f(k + 1, vi(k + 1));
    f[0][0] = 1;
    for (auto x: a) {
        vector<vi> g(k + 1, vi(k + 1));
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= i; j++) {
                g[i][j] = f[i][j];
                if (i < x) continue;
                g[i][j] |= f[i - x][j];
                if (j < x) continue;
                g[i][j] |= f[i - x][j - x];
            }
        }
        f = g;
    }

    vi ans;
    for (int i = 0; i <= k; i++) {
        if (f[k][i]) {
            ans.push_back(i);
        }
    }
    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}