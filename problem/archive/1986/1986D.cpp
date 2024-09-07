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

    int ans = 2e9, pre = 0;
    for (int i = 0; i < n - 1; i++) {
        int cur = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (cur == 0) {
            cout << 0 << endl;
            return;
        }
        int tot = pre;
        if (cur > 1) {
            tot += cur;
        }
        for (int j = i + 2; j < n; j++) {
            int nxt = s[j] - '0';
            if (nxt == 0) {
                cout << 0 << endl;
                return;
            }
            if (nxt > 1) {
                tot += nxt;
            }
        }
        ans = min(ans, max(1, tot));
        cur = s[i] - '0';
        if (cur == 0 && i < n - 2) {
            cout << 0 << endl;
            return;
        }
        if (cur > 1) {
            pre += cur;
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