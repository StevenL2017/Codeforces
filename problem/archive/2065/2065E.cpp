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
    int n, m, k;
    cin >> n >> m >> k;

    vector<char> a(2, '0');
    a[1] = '1';
    if (n < m) {
        swap(n, m);
        swap(a[0], a[1]);
    }

    if (k < n - m || k > n) {
        cout << -1 << endl;
        return;
    }

    string ans;
    while (n || m) {
        if (n >= k) {
            ans += string(k, a[0]);
            n -= k;
        } else {
            ans += string(n, a[0]);
            n = 0;
        }
        if (m >= k) {
            ans += string(k, a[1]);
            m -= k;
        } else {
            ans += string(m, a[1]);
            m = 0;
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