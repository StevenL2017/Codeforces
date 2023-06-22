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

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    if (mn == mx) {
        cout << 0 << " " << n * 1ll * (n - 1) / 2 << endl;
    } else {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == mn) c1++;
            if (a[i] == mx) c2++;
        }
        cout << mx - mn << " " << c1 * 1ll * c2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}