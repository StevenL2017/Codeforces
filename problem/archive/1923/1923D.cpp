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
    int n;
    cin >> n;
    vi a(n);
    in(a);

    vi ans(n, n);
    for (int c = 0; c < 2; c++) {
        vector<ll> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + a[i];
        }
        vi pos(n, -1);
        for (int i = 1; i < n; i++) {
            int j = (c ? n - 1 - i : i);
            int left = 1, right = i;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (pre[i] - pre[i - mid] > a[i] && pos[i - 1] >= i - mid) {
                    ans[j] = min(ans[j], mid);
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (a[i - 1] > a[i]) ans[j] = 1;
            pos[i] = (a[i] == a[i - 1] ? pos[i - 1] : i - 1);
        }
        reverse(a.begin(), a.end());
    }

    for (int i = 0; i < n; i++) {
        cout << (ans[i] == n ? -1 : ans[i]) << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}