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

    vi ans(n, 0);
    function<void(int, int, int)> dfs = [&] (int l, int r, int d) {
        if (l > r) return;
        int mx = 0, idx = -1;
        for (int i = l; i <= r; i++) {
            if (a[i] > mx) {
                mx = a[i];
                idx = i;
            }
        }
        ans[idx] = d;
        dfs(l, idx - 1, d + 1);
        dfs(idx + 1, r, d + 1);
    };
    dfs(0, n - 1, 0);

    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}