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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in(a);

    int left = 0, c0 = 0, mx = -1;
    int l = -1, r = -1;
    for (int right = 0; right < n; right++) {
        if (a[right] == 0) {
            c0++;
        }
        while (left <= right && c0 > k) {
            if (a[left] == 0) {
                c0--;
            }
            left++;
        }
        if (right - left + 1 > mx) {
            mx = right - left + 1;
            l = left;
            r = right;
        }
    }

    for (int i = l; i <= r; i++) {
        a[i] = 1;
    }

    cout << mx << endl;
    out(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}