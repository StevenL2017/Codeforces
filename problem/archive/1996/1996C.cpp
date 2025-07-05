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
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vector<vi> cnt1(26, vi(n + 1)), cnt2(26, vi(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt1[j][i + 1] = cnt1[j][i] + (int)(a[i] - 'a' == j);
            cnt2[j][i + 1] = cnt2[j][i] + (int)(b[i] - 'a' == j);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = 0;
        for (int j = 0; j < 26; j++) {
            int c1 = cnt1[j][r] - cnt1[j][l - 1];
            int c2 = cnt2[j][r] - cnt2[j][l - 1];
            if (c1 > c2) {
                ans += c1 - c2;
            }
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