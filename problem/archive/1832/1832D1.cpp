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
    int n, q; cin >> n >> q;
    vi a(n); in(a);

    sort(a.begin(), a.end());

    while (q--) {
        int k; cin >> k;

        vi b = a;
        for (int i = 0; i < n; i++) {
            if (k == 0) {
                break;
            }
            if (k % 2 == 0 && i == n - 1) {
                break;
            }
            b[i] += k;
            k--;
        }

        k /= 2;
        sort(b.begin(), b.end());
        ll diff = 0;
        for (int i = 0; i < n; i++) {
            diff += b[i] - b[0];
        }
        int ans = b[0];
        if (k > diff) {
            k -= diff;
            ans -= (k + n - 1) / n;
        }

        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}