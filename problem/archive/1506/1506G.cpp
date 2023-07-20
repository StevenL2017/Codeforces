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
    vi suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] |= suf[i + 1];
        suf[i] |= 1 << (s[i] - 'a');
    }
    vector<vi> idx(26);
    for (int i = 0; i < n; i++) {
        idx[s[i] - 'a'].push_back(i);
    }

    string ans;
    int mask = suf[0];
    int m = __builtin_popcount(mask), k = 0;
    while (m--) {
        for (int i = 25; i >= 0; i--) {
            if (mask >> i & 1) {
                int j = lower_bound(idx[i].begin(), idx[i].end(), k) - idx[i].begin();
                if (j < ssz(idx[i]) && (suf[idx[i][j]] & mask) == mask) {
                    ans += (char)(i + 'a');
                    mask ^= 1 << i;
                    k = idx[i][j];
                    break;
                }
            }
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