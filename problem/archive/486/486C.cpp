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
    int n, p; cin >> n >> p;
    string s; cin >> s;

    if (p > (n + 1) / 2) p = n + 1 - p;
    p--;

    auto calc1 = [&] () -> int {
        int ans = 0, cur = p;
        for (int i = p; i < (n + 1) / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                ans += min((s[i] - s[n - 1 - i] + 26) % 26, (s[n - 1 - i] - s[i] + 26) % 26);
                ans += i - cur;
                cur = i;
            }
        }
        for (int i = p - 1; i >= 0; i--) {
            if (s[i] != s[n - 1 - i]) {
                ans += min((s[i] - s[n - 1 - i] + 26) % 26, (s[n - 1 - i] - s[i] + 26) % 26);
                ans += cur - i;
                cur = i;
            }
        }
        return ans;
    };

    auto calc2 = [&] () -> int {
        int ans = 0, cur = p;
        for (int i = p; i >= 0; i--) {
            if (s[i] != s[n - 1 - i]) {
                ans += min((s[i] - s[n - 1 - i] + 26) % 26, (s[n - 1 - i] - s[i] + 26) % 26);
                ans += cur - i;
                cur = i;
            }
        }
        for (int i = p + 1; i < (n + 1) / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                ans += min((s[i] - s[n - 1 - i] + 26) % 26, (s[n - 1 - i] - s[i] + 26) % 26);
                ans += i - cur;
                cur = i;
            }
        }
        return ans;
    };

    cout << min(calc1(), calc2()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}