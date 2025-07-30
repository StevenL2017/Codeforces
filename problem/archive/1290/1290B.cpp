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
    int q;
    cin >> q;

    int n = ssz(s);
    vector<vi> pre(26, vi(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            pre[j][i + 1] = pre[j][i] + (int)(s[i] - 'a' == j);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l == r || s[l - 1] != s[r - 1]) {
            cout << "Yes" << endl;
            continue;
        }

        int cnt = 0;
        for (int j = 0; j < 26; j++) {
            if (pre[j][r] - pre[j][l - 1] > 0) {
                cnt++;
            }
        }
        if (cnt >= 3) {
            cout << "Yes" << endl;
            continue;
        }

        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}