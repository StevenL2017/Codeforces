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
    string s;
    cin >> s;

    vi cnt(26);
    for (auto c : s) {
        cnt[c - 'a']++;
    }

    auto calc = [&] (int d) -> int {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int c = 0;
            for (int j = 0; j < 26; j++) {
                c += cnt[j] / i;
            }
            if (c >= d) {
                ans = max(ans, d * i);
            }
        }
        return ans;
    };

    int ans = *max_element(cnt.begin(), cnt.end());
    ans = max(ans, calc(k));
    int x = 2;
    while (x * x <= k) {
        if (k % x == 0) {
            ans = max(ans, calc(x));
            if (x * x < k) {
                ans = max(ans, calc(k / x));
            }
        }
        x++;
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