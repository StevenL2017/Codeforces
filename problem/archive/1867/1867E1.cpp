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

    int ans = 0;
    for (int i = 1; i + k <= n - n % k; i += k) {
        int x = query(i);
        ans ^= x;
    }
    for (int i = n - n % k - k + 1; i + k <= n + 1; i++) {
        int x = query(i);
        ans ^= x;
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