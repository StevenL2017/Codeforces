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

int calc(string s, string t) {
    int n = ssz(s);
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == '0' && s[i + 2] == '0') {
            t[i + 1] = '1';
        }
    }
    for (int i = 0; i < n - 2; i++) {
        if (t[i] == '1' && t[i + 2] == '1') {
            s[i + 1] = '1';
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans++;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    string a = s, b = t;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == '0' && s[i + 2] == '0') {
            b[i + 1] = '1';
        }
    }
    for (int i = 0; i < n - 2; i++) {
        if (b[i] == '1' && b[i + 2] == '1') {
            a[i + 1] = '1';
        }
    }

    vi pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (int)(a[i] == '1');
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        if (r - l + 1 < 5) {
            cout << calc(s.substr(l, r - l + 1), t.substr(l, r - l + 1)) << endl;
            continue;
        }

        int ans = pre[r - 1] - pre[l + 2];
        ans += (int)(s[l] == '1') + (int)(s[r] == '1');
        if (t[l] == '1' && b[l + 2] == '1' || s[l + 1] == '1') {
            ans++;
        }
        if (t[r] == '1' && b[r - 2] == '1' || s[r - 1] == '1') {
            ans++;
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}