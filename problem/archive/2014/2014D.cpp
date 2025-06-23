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
    int n, d, k;
    cin >> n >> d >> k;
    map<int, int> left, right;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        left[l - 1]++;
        right[r - 1]++;
    }

    vi ans(2);
    int mx = 0, mn = k + 1, cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += left[i];
        cnt -= right[i - d];
        if (i >= d - 1) {
            if (cnt > mx) {
                mx = cnt;
                ans[0] = i - d + 2;
            }
            if (cnt < mn) {
                mn = cnt;
                ans[1] = i - d + 2;
            }
        }
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