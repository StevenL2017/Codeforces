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
    ll n, k; cin >> n >> k;

    ll f = 1, g = 1;
    for (int i = 0; i < k - 3; i++) {
        int temp = f;
        f += g;
        g = temp;
        if (f > n) {
            cout << 0 << endl;
            return;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (n - i * g >= 0 && (n - i * g) % f == 0) {
            auto j = (n - i * g) / f;
            if (i <= j) ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}