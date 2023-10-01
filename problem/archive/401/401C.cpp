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
    int n, m;
    cin >> n >> m;

    if (m < n - 1 || 2 * n < m - 2) {
        cout << -1 << endl;
        return;
    }

    string ans(n + m, '1');
    if (n >= m) {
        for (int i = 0; i < n + m; i += 2) {
            ans[i] = '0';
        }
    } else {
        int j = 2;
        for (int i = 0; i < m - n; i++) {
            ans[j] = '0';
            j += 3;
        }
        j--;
        for (; j < n + m; j += 2) {
            ans[j] = '0';
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}