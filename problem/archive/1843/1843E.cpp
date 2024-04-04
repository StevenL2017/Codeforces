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
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int q;
    cin >> q;
    vi nums(q);
    in(nums);

    auto check = [&] (int mid) -> bool {
        vi pre(n + 1);
        for (int i = 0; i < mid; i++) {
            pre[nums[i]] = 1;
        }
        for (int i = 0; i < n; i++) {
            pre[i + 1] += pre[i];
        }
        for (int i = 0; i < m; i++) {
            int l = a[i].first, r = a[i].second;
            int s = pre[r] - pre[l - 1];
            if (s * 2 > r - l + 1) {
                return true;
            }
        }
        return false;
    };

    int ans = q + 1;
    int left = 0, right = q;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << (ans <= q ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}