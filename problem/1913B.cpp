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
    string s; cin >> s;

    int n = ssz(s);
    int c0 = 0, c1 = 0;
    for (auto c : s) {
        if (c == '0') c0++;
        else c1++;
    }

    auto check = [&] (int x) -> bool {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n - x; i++) {
            if (s[i] == '1') cnt0++;
            else cnt1++;
        }
        return (cnt0 <= c0 && cnt1 <= c1);
    };

    int left = 0, right = n;
    int ans = right;
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