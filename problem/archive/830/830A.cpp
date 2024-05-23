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
    int n, k, p;
    cin >> n >> k >> p;
    vi a(n), b(k);
    in(a); in(b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto check = [&] (int mid) -> bool {
        vi used(k);
        int cnt = 0, i = 0;
        for (int j = 0; j < n && a[j] <= p; j++) {
            int x = a[j];
            bool ok = false;
            while (i < k) {
                if (used[i]) {
                    i++;
                    continue;
                }
                int d = INT_MAX;
                if (b[i] <= x) {
                    d = (x - b[i]) * 2 + p - x;
                } else if (b[i] <= p) {
                    d = p - x; 
                } else {
                    d = (b[i] - p) * 2 + p - x;
                }
                if (d <= mid) {
                    used[i++] = 1;
                    cnt++;
                    ok = true;
                    break;
                }
                if (b[i] > p) break;
                i++;
            }
            if (!ok) return false;
        }
        i = k - 1;
        for (int j = n - 1; j >= 0 && a[j] > p; j--) {
            int x = a[j];
            bool ok = false;
            while (i >= 0) {
                if (used[i]) {
                    i--;
                    continue;
                }
                int d = INT_MAX;
                if (b[i] >= x) {
                    d = (b[i] - x) * 2 + x - p;
                } else if (b[i] >= p) {
                    d = x - p; 
                } else {
                    d = (p - b[i]) * 2 + x - p;
                }
                if (d <= mid) {
                    used[i--] = 1;
                    cnt++;
                    ok = true;
                    break;
                }
                if (b[i] < p) break;
                i--;
            }
            if (!ok) return false;
        }
        return cnt == n;
    };

    int left = 0, right = 2e9, ans = right;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
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