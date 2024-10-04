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
    string s;
    cin >> s;

    if (n & 1) {
        cout << -1 << endl;
        return;
    }

    vi cnt(26);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i]) {
            cnt[s[i] - 'a']++;
        }
    }

    int tot = 0, mx = 0, idx = -1;
    for (int i = 0; i < 26; i++) {
        tot += cnt[i];
        if (cnt[i] > mx) {
            mx = cnt[i];
            idx = i;
        }
    }

    if (mx <= tot / 2) {
        cout << (tot + 1) / 2 << endl;
        return;
    }

    int ans = tot - mx;
    mx -= ans;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i] && s[i] - 'a' != idx && s[n - 1 - i] - 'a' != idx) {
            mx--;
            ans++;
            if (!mx) break;
        }
    }

    if (mx) {
        cout << -1 << endl;
        return;
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