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
    int n, k; cin >> n >> k;
    vi a(n); in(a);

    auto check = [&] (int x) -> bool {
        for (int i = 0; i < n; i++) {
            if (x <= a[i]) return true;
            if (i == n - 1) break;
            int cur = x, cnt = 0;
            for (int j = i + 1; j < n; j++) {
                cnt += cur - a[j - 1];
                if (cnt > k) break;
                if (--cur <= a[j]) break;
                if (j == n - 1) cnt = k + 1;
            }
            if (cnt <= k) return true;
        }
        return false;
    };

    int left = *max_element(a.begin(), a.end());
    int right = left + n;
    int ans = left;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
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