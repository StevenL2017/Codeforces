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

int query(int i) {
    cout << "? " << i << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int ans = 0, i = 0;
    for (i = 1; i <= n - 2 * k + 1; i += k) {
        ans ^= query(i);
    }
    if (i == n - k + 1) {
        ans ^= query(i);
    } else {
        int y = (n - k + 1 - i) / 2;
        ans ^= query(i);
        ans ^= query(i + y);
        ans ^= query(i + 2 * y);
    }

    cout << "! " << ans << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}