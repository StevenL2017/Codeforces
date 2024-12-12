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
    int n, x;
    cin >> n >> x;
    vi a(n);
    in(a);

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            idx = i + 1;
            break;
        }
    }

    int l = 0, r = n;
    while (l + 1 < r) {
        auto mid = (l + r) / 2;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << 1 << endl;
    cout << idx << " " << l + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}