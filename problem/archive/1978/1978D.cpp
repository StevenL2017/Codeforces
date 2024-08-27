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
    int n, c;
    cin >> n >> c;
    vi a(n);
    in(a);

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int mx = *max_element(a.begin() + 1, a.end());
    int winner = (a[0] + c >= mx ? 0 : find(a.begin() + 1, a.end(), mx) - a.begin());
    ll tot = c;
    vi ans(n);
    for (int i = 0; i < n; i++) {
        if (i == winner) {
            ans[i] = 0;
        } else if (tot + a[i] >= mx) {
            ans[i] = i;
        } else {
            ans[i] = i + 1;
        }
        tot += a[i];
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