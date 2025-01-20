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
    string s;
    cin >> s;

    int n = ssz(s), cnt1 = 0;
    for (auto c: s) {
        if (c == '1') {
            cnt1++;
        }
    }

    auto check = [&] (int x) -> bool {
        int c0 = 0, c1 = cnt1;
        for (int l = 0, r = 0; r < n; r++) {
            if (s[r] == '0') c0++;
            else c1--;
            while (l <= r && c0 > x) {
                if (s[l] == '0') c0--;
                else c1++;
                l++;
            }
            if (c1 <= x) return true;
        }
        return false;
    };

    int left = 0, right = n;
    int ans = n;
    while (left <= right) {
        auto mid = (left + right) / 2;
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
    cin >> t;
    while (t--) solve();
}